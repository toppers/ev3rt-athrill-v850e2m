#ifndef _EV3_VDEV_COMMON_H_
#define _EV3_VDEV_COMMON_H_

/*
 * RX
 */
#define EV3_GPIO_BTN_OFF	(0U)
#define EV3_GPIO_BTN_BITS_LEFT	(0U)
#define EV3_GPIO_BTN_BITS_RIGHT	(1U)
#define EV3_GPIO_BTN_BITS_UP	(2U)
#define EV3_GPIO_BTN_BITS_DOWN	(3U)
#define EV3_GPIO_BTN_BITS_ENTER	(4U)
#define EV3_GPIO_BTN_BITS_BACK	(5U)


#define EV3_SENSOR_OFF				(2U)
#define EV3_SENSOR_OFF_TYPE(index)	(EV3_SENSOR_OFF + ((index) * 2U))
#define EV3_SENSOR_INX_AMBIENT		(0U)
#define EV3_SENSOR_INX_COLOR		(1U)
#define EV3_SENSOR_INX_REFLECT		(2U)
#define EV3_SENSOR_INX_RGB_R		(3U)
#define EV3_SENSOR_INX_RGB_G		(4U)
#define EV3_SENSOR_INX_RGB_B		(5U)
#define EV3_SENSOR_INX_ANGLE		(6U)
#define EV3_SENSOR_INX_RATE			(7U)
#define EV3_SENSOR_INX_IR_D			(8U)
#define EV3_SENSOR_INX_IR_0			(9U)
#define EV3_SENSOR_INX_IR_0_H		(10U)
#define EV3_SENSOR_INX_IR_0_D		(11U)
#define EV3_SENSOR_INX_IR_1			(12U)
#define EV3_SENSOR_INX_IR_1_H		(13U)
#define EV3_SENSOR_INX_IR_1_D		(14U)
#define EV3_SENSOR_INX_IR_2			(15U)
#define EV3_SENSOR_INX_IR_2_H		(16U)
#define EV3_SENSOR_INX_IR_2_D		(17U)
#define EV3_SENSOR_INX_IR_3			(18U)
#define EV3_SENSOR_INX_IR_3_H		(19U)
#define EV3_SENSOR_INX_IR_3_D		(20U)
#define EV3_SENSOR_INX_ULTRASONIC	(21U)
#define EV3_SENSOR_INX_ULTRASONIC_LISTEN	(22U)
#define EV3_SENSOR_INX_AXES_X		(23U)
#define EV3_SENSOR_INX_AXES_Y		(24U)
#define EV3_SENSOR_INX_AXES_Z		(25U)
#define EV3_SENSOR_INX_TEMP			(26U)
#define EV3_SENSOR_INX_TOUCH		(27U)

/*
 * TX
 */
#define EV3_GPIO_LED_OFF	(0U)
#define EV3_GPIO_LED_BITS_RED		(0U)
#define EV3_GPIO_LED_BITS_GREEN		(1U)
#define EV3_GPIO_LED_BITS_YELLOW	(2U)
#define EV3_GPIO_LED_BITS_BLUE		(3U)


#endif /* _EV3_VDEV_COMMON_H_ */
