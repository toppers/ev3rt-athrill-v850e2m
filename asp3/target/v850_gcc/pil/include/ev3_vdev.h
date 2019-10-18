#ifndef _EV3_VDEV_H_
#define _EV3_VDEV_H_

#include "vdev.h"
#include "ev3_vdev_common.h"

/*
 * Button(RX)
 * 1byte data
 */
//LEFT, RIGHT, UP, DOWN, ENTER,BACK
#define EV3_GPIO_BTN_LEFT	(1U << EV3_GPIO_BTN_BITS_LEFT)
#define EV3_GPIO_BTN_RIGHT	(1U << EV3_GPIO_BTN_BITS_RIGHT)
#define EV3_GPIO_BTN_UP		(1U << EV3_GPIO_BTN_BITS_UP)
#define EV3_GPIO_BTN_DOWN	(1U << EV3_GPIO_BTN_BITS_DOWN)
#define EV3_GPIO_BTN_ENTER	(1U << EV3_GPIO_BTN_BITS_ENTER)
#define EV3_GPIO_BTN_BACK	(1U << EV3_GPIO_BTN_BITS_BACK)
#define EV3_GPIO_BTN_ADDR	(VDEV_RX_DATA_BASE + EV3_GPIO_BTN_OFF)

/*
 * LED(TX)
 * 1byte data
 */
//RED, GREEN, YELLOW, BLUE
#define EV3_GPIO_LED_RED	(1U << 0)
#define EV3_GPIO_LED_GREEN	(1U << 1)
#define EV3_GPIO_LED_YELLOW	(1U << 2)
#define EV3_GPIO_LED_BLUE	(1U << 3)
#define EV3_GPIO_LED_ADDR	(VDEV_TX_DATA_BASE + EV3_GPIO_LED_OFF)



#endif /* _EV3_VDEV_H_ */
