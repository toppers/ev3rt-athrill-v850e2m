#include <kernel.h>
#include <t_syslog.h>
#include <t_stdlib.h>
#include "syssvc/serial.h"
#include "syssvc/syslog.h"
#include "kernel_cfg.h"
#include "gpio_dri.h"
#include "ev3_vdev.h"
#include "sil.h"

#include "driver_common.h"


bool_t gpio_get_value(uint32_t pin) {
	bool_t ret = FALSE;
	uint32_t base = pin / EV3_GPIO_PIN_BASE_SIZE;
	uint32_t index = pin % EV3_GPIO_PIN_BASE_SIZE;
	uint8_t data;

	switch (base) {
	case 1: //BUTTON
		data = sil_reb_mem((const uint8_t *)EV3_GPIO_BTN_ADDR);
		if ((data & (1U << index)) != 0U) {
			ret = TRUE;
		}
		break;
	default:
		break;
	}
	return ret;
}

void gpio_set_value(uint32_t pin, bool_t value) {
	uint32_t base = pin / EV3_GPIO_PIN_BASE_SIZE;
	uint32_t index = pin % EV3_GPIO_PIN_BASE_SIZE;
	uint8_t * addr;
	uint8_t data;

	switch (base) {
	case 0: //LED
		addr = (uint8_t *)EV3_GPIO_LED_ADDR;
		break;
	default:
		return;
	}
	data = sil_reb_mem(addr);


	if(value == TRUE) {
		data |= (1U << index);
    }
    else {
		data &= ~(1U << index);
    }
	sil_wrb_mem(addr, data);
	return;
}
void gpio_out_flush(void)
{
	sil_wrb_mem((void*)VDEV_TX_FLAG_BASE, 1);
}
