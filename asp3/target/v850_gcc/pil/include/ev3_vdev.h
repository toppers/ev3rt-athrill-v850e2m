#ifndef _EV3_VDEV_H_
#define _EV3_VDEV_H_

#include "vdev.h"

/*
 * Button(RX)
 * 1byte data
 */
//LEFT, RIGHT, UP, DOWN, ENTER,BACK
#define EV3_GPIO_BTN_LEFT	(1U << 0)
#define EV3_GPIO_BTN_RIGHT	(1U << 1)
#define EV3_GPIO_BTN_UP		(1U << 2)
#define EV3_GPIO_BTN_DOWN	(1U << 3)
#define EV3_GPIO_BTN_ENTER	(1U << 4)
#define EV3_GPIO_BTN_BACK	(1U << 4)
#define EV3_GPIO_BTN_ADDR	(VDEV_RX_DATA_BASE + 0U)

/*
 * LED(TX)
 * 1byte data
 */
//RED, GREEN, YELLOW, BLUE
#define EV3_GPIO_LED_RED	(1U << 0)
#define EV3_GPIO_LED_GREEN	(1U << 1)
#define EV3_GPIO_LED_YELLOW	(1U << 2)
#define EV3_GPIO_LED_BLUE	(1U << 3)
#define EV3_GPIO_LED_ADDR	(VDEV_TX_DATA_BASE + 0U)



#endif /* _EV3_VDEV_H_ */
