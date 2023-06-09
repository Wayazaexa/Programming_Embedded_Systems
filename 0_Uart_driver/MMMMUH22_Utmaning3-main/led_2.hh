#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "uart.hh"
#include "stm32f4xx.h"

#define	LED_PORT 		GPIOB

#define	LED_PORT_CLOCK  (1U<<1)

#define LED_RED_PIN	(1U<<14)
#define LED_GREEN_PIN	(1U<<12)
#define	LED_BLUE_PIN	(1U<<15)
#define LED_YELLOW_PIN	(1U<<13)

#define LED_RED_MODE_BIT  (1U<<28)
#define LED_GREEN_MODE_BIT (1U<<24)
#define LED_YELLOW_MODE_BIT (1U<<26)
#define LED_BLUE_MODE_BIT (1U<<30)


class Led
{
public:
	Led();
}

#endif
