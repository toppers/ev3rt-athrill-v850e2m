#include "uart_dri.h"
#include "ev3_vdev.h"
#include "sil.h"
#include <string.h>

void uart_dri_get_data_ultrasonic(uint8_t mode, void *dest, SIZE size)
{
	uint16_t data;
	const uint16_t *addr;
	switch (mode) {
	case 0:
		addr = (const uint16_t *)EV3_SENSOR_ADDR_ULTRASONIC;
		break;
	case 2:
		addr = (const uint16_t *)EV3_SENSOR_ADDR_ULTRASONIC_LISTEN;
		break;
	default:
		return;
	}
	data = sil_reh_mem(addr);
	memcpy(dest, (void*)&data, sizeof(data));
	return;
}
void uart_dri_get_data_gyro(uint8_t mode, void *dest, SIZE size)
{
	uint16_t data;
	const uint16_t *addr;
	switch (mode) {
	case 0:
		addr = (const uint16_t *)EV3_SENSOR_ADDR_ANGLE;
		break;
	case 1:
		addr = (const uint16_t *)EV3_SENSOR_ADDR_RATE;
		break;
	default:
		return;
	}
	data = sil_reh_mem(addr);
	memcpy(dest, (void*)&data, sizeof(data));
	return;
}
void uart_dri_get_data_touch(uint8_t mode, void *dest, SIZE size)
{
	uint16_t data ;
	const uint16_t *addr = (const uint16_t *)EV3_SENSOR_ADDR_TOUCH;;
	data = sil_reh_mem(addr);
	memcpy(dest, (void*)&data, sizeof(data));
	return;
}
void uart_dri_get_data_color(uint8_t mode, void *dest, SIZE size)
{
	uint16_t *array = (uint16_t*)dest;

	array[0] = sil_reh_mem( (const uint16_t *)EV3_SENSOR_ADDR_RGB_R);
	array[1] = sil_reh_mem( (const uint16_t *)EV3_SENSOR_ADDR_RGB_G);
	array[2] = sil_reh_mem( (const uint16_t *)EV3_SENSOR_ADDR_RGB_B);

	return;
}
void uart_dri_get_data_ir(uint8_t mode, void *dest, SIZE size)
{
	int8_t *array = (int8_t*)dest;
	switch (mode) {
	case 0:
		array[0] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_D);
		break;
	case 1:
		array[0] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_0_H);
		array[1] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_0_D);
		array[2] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_1_H);
		array[3] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_1_D);
		array[4] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_2_H);
		array[5] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_2_D);
		array[6] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_3_H);
		array[7] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_3_D);
		break;
	case 2:
		array[0] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_0);
		array[1] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_1);
		array[2] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_2);
		array[3] = (int8_t)sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_IR_3);
		break;
	default:
		return;
	}
	return;
}
void uart_dri_get_data_accel(uint8_t mode, void *dest, SIZE size)
{
	int16_t *array = (int16_t*)dest;
	array[0] = sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_AXES_X);
	array[1] = sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_AXES_Y);
	array[2] = sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_AXES_Z);
	return;
}
void uart_dri_get_data_temp(uint8_t mode, void *dest, SIZE size)
{
	int16_t *array = (int16_t*)dest;
	array[0] = sil_reh_mem((const uint16_t *)EV3_SENSOR_ADDR_TMP);
	return;
}
