#include <ev3api.h>
#include <app.h>
#include <math.h>

#if defined(BUILD_MODULE)
#include "module_cfg.h"
#else
#include "kernel_cfg.h"
#endif

#define DEBUG

#ifdef DEBUG
#define _debug(x) (x)
#else
#define _debug(x)
#endif

typedef enum {
	RUNNING,
}state_run_t;

static const sensor_port_t
color_sensor = EV3_PORT_2;

static const motor_port_t
tail_motor  = EV3_PORT_A,
right_motor = EV3_PORT_B,
left_motor  = EV3_PORT_C,
arm_motor   = EV3_PORT_D;

void main_task(intptr_t exinf)
{
	ev3_led_set_color(LED_OFF);
	
	ev3_sensor_config(color_sensor, COLOR_SENSOR);

	ev3_motor_config(tail_motor, LARGE_MOTOR);
	ev3_motor_config(left_motor, LARGE_MOTOR);
	ev3_motor_config(right_motor, LARGE_MOTOR);
	ev3_motor_config(arm_motor, LARGE_MOTOR);
		
	ev3_led_set_color(LED_GREEN);
	
	sta_cyc(MOTOR_CONTROL_TASK_CYC);

	ext_tsk();

}

void motor_control_task(intptr_t exinf){

	static state_run_t status = RUNNING;
	int32_t	motor_power = 20;
	int32_t	left_motor_power, right_motor_power;
	float KP = 0.2F;
	int target_brightness = 80;
	rgb_raw_t rgb_val = {0,0,0};
	int turn_val;
syslog(LOG_NOTICE,"lc:%3d, rc:%3d",ev3_motor_get_counts(left_motor),ev3_motor_get_counts(right_motor));
	switch(status){
		case RUNNING:
			
			if(ev3_motor_get_counts(left_motor)<=3000
			&& ev3_motor_get_counts(right_motor)<=3000){
				ev3_motor_set_power(left_motor, 80);
				ev3_motor_set_power(right_motor, 80);
			}
			else{
				ev3_motor_stop(left_motor, 1);
				ev3_motor_stop(right_motor, 1);
			}
		
		break;
		default:
			ev3_led_set_color(LED_RED);
		break;
	}
		
	ext_tsk();

}