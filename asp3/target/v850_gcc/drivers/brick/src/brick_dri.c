/*
 * driver_common.c
 *
 *  Created on: Nov 4, 2013
 *      Author: liyixiao
 */

#include "target_syssvc.h"
#include "driver_common.h"
#include "kernel_cfg.h"
#include "kernel/kernel_impl.h"
#include "tlsf.h"
#include "platform.h"
#include "brick_dri.h"
#include "ev3.h"
#include "gpio_dri.h"

/**
 * Global brick information (singleton & shared by all drivers)
 */
brickinfo_t global_brick_info;

/**
 * Application heap
 */
static uint8_t appheap[APP_HEAP_SIZE] __attribute__((section(".appheap")));

/**
 * Buttons
 */

static ISR      button_handlers[TNUM_BRICK_BUTTON];
static intptr_t button_exinfs[TNUM_BRICK_BUTTON];
static bool_t   button_pressed[TNUM_BRICK_BUTTON];

/**
 * This task runs in TDOM_APP.
 * However, since this module (brick_dri.o) is readable & executable in all protection domains,
 * there should be no problem to put this function here.
 */
void brick_button_task(intptr_t unused) {
	ER ercd;
	int i;
	FLGPTN flgptn;
	while((ercd = wai_flg(BTN_CLICK_FLG, (1 << TNUM_BRICK_BUTTON) - 1, TWF_ORW, &flgptn)) == E_OK) {
		for (i = 0; i < TNUM_BRICK_BUTTON; ++i)
			if (flgptn & (1 << i)) {
				/**
				 * Note: Since this task has the highest priority of all application tasks,
				 * it should be safe to copy handler & exinf without a lock.
				 * TODO: Use a lock
				 */
				ISR handler = button_handlers[i];
				intptr_t exinf = button_exinfs[i];

#if 0 // TODO: A bug in 'ret_service' will always clear 'waifbd' in TCB
				ercd = dis_wai(TSK_SELF);
				assert(ercd == E_OK);
                T_RTSK rtsk;
                ercd = ref_tsk(TSK_SELF, &rtsk);
				assert(ercd == E_OK);
                syslog(LOG_ERROR, "waifbd: %d", rtsk.waifbd);
#endif
                if (handler != NULL) handler(exinf);
#if 0
				ercd = ena_wai(TSK_SELF);
				assert(ercd == E_OK);
                if (ercd != E_OK)
	                syslog(LOG_ERROR, "%s(): ena_wai() failed, ercd: %d", __FUNCTION__, ercd);
#endif
			}
	}
	syslog(LOG_ERROR, "%s(): Fatal error, ercd: %d", __FUNCTION__, ercd);
}


typedef ulong_t EVTTIM;
extern EVTTIM _kernel_current_time; // From time_event.c
ID current_button_flag;
EVTTIM _kernel_current_time;

#define TODO_GPIO	0

/**
 * Cyclic handler to update button status
 */
void brick_button_cyc(intptr_t unused) {
	int i;
	static const int button_pin[TNUM_BRICK_BUTTON] = {
	    [BRICK_BUTTON_LEFT]   = TODO_GPIO,
	    [BRICK_BUTTON_RIGHT]  = TODO_GPIO,
	    [BRICK_BUTTON_UP]     = TODO_GPIO,
	    [BRICK_BUTTON_DOWN]   = TODO_GPIO,
	    [BRICK_BUTTON_ENTER]  = TODO_GPIO,
	    [BRICK_BUTTON_BACK]   = TODO_GPIO
	};

    // Support force shutdown feature
    static EVTTIM power_off_start_time;
    if (gpio_get_value(button_pin[BRICK_BUTTON_BACK]) && gpio_get_value(button_pin[BRICK_BUTTON_LEFT]) && gpio_get_value(button_pin[BRICK_BUTTON_RIGHT])) {
        if (!(button_pressed[BRICK_BUTTON_BACK] && button_pressed[BRICK_BUTTON_LEFT] && button_pressed[BRICK_BUTTON_RIGHT]))
            power_off_start_time = _kernel_current_time;
        else if (_kernel_current_time - power_off_start_time >= FORCE_SHUTDOWN_TIMEOUT)
            brick_misc_command(MISCCMD_POWER_OFF, 0);
    }

    static bool_t ignore_back_click_once = false; // Quick fix

	// Hold BACK button to call EV3RT console
    static EVTTIM console_start_time;
    if (gpio_get_value(button_pin[BRICK_BUTTON_BACK])) {
        if (!(button_pressed[BRICK_BUTTON_BACK]))
        	console_start_time = _kernel_current_time;
        else if (_kernel_current_time - console_start_time >= FORCE_SHUTDOWN_TIMEOUT * 2) {
        	if (current_button_flag != console_button_flag) {
        		current_button_flag = console_button_flag;
        		ignore_back_click_once = true;
        		SVC_PERROR(iset_flg(current_button_flag, 1 << BRICK_BUTTON_BACK));
        	}
        }
    }

	for (i = 0; i < TNUM_BRICK_BUTTON; ++i) {
		bool_t pressed = gpio_get_value(button_pin[i]);
		if (button_pressed[i] && !pressed) { // Clicked
			if (i == BRICK_BUTTON_BACK && ignore_back_click_once)
				ignore_back_click_once = false;
			else
				SVC_PERROR(iset_flg(current_button_flag, 1 << i));
		}
		button_pressed[i] = pressed;
	}

}

static void initialize(intptr_t unused) {
	init_memory_pool(APP_HEAP_SIZE, appheap);
	global_brick_info.app_heap = appheap;
	global_brick_info.button_pressed = button_pressed;
	current_button_flag = user_button_flag;
#if defined(DEBUG) || 1
    syslog(LOG_NOTICE, "brick_dri initialized.");
#endif
}

static void softreset(intptr_t unused) {
	int i;
	/**
	 * global_brick_info must have been fully initialized when this function is called
	 */
	//assert(global_brick_info.analog_sensors != NULL);
	assert(global_brick_info.app_heap != NULL);
	assert(global_brick_info.button_pressed != NULL);
	//assert(global_brick_info.motor_data != NULL);
	//assert(global_brick_info.motor_ready != NULL);
	//assert(global_brick_info.uart_sensors != NULL);

	ER ercd;

	SVC_PERROR(stp_cyc(BRICK_BTN_CYC));
	ercd = ter_tsk(BRICK_BTN_TSK);
	assert(ercd == E_OK || ercd == E_OBJ);
	destroy_memory_pool(appheap);
	init_memory_pool(APP_HEAP_SIZE, appheap);
	for (i = 0; i < TNUM_BRICK_BUTTON; i++) {
		button_handlers[i] = NULL;
		button_exinfs[i]   = 0;
		button_pressed[i]  = false;
	}
	SVC_PERROR(act_tsk(BRICK_BTN_TSK));
	SVC_PERROR(sta_cyc(BRICK_BTN_CYC));
}

void initialize_brick_dri(intptr_t unused) {
	ev3_driver_t driver;
	driver.init_func = initialize;
	driver.softreset_func = softreset;
	SVC_PERROR(platform_register_driver(&driver));
}

/**
 * Implementation of extended service calls
 */

ER _fetch_brick_info(brickinfo_t *p_brickinfo, ID cdmid) {

	*p_brickinfo = global_brick_info;

	return E_OK;
}

ER _button_set_on_clicked(brickbtn_t button, ISR handler, intptr_t exinf) {
	if(button >= TNUM_BRICK_BUTTON)
		return E_ID;

	ER ercd;

	ercd = loc_cpu();
	assert(ercd == E_OK);

	button_handlers[button] = handler;
	button_exinfs[button] = exinf;

	ercd = unl_cpu();
	assert(ercd == E_OK);

	return E_OK;
}

ER _brick_misc_command(misccmd_t misccmd, intptr_t exinf) {
    switch(misccmd) {
    case MISCCMD_POWER_OFF:
    	//TODO
        break;

    case MISCCMD_SET_LED:
    	//TODO
        break;

    case CMD_BUSY_WAIT_INIT:
    	//TODO
    	break;

    default:
        return E_ID;
    }

    return E_OK;
}


