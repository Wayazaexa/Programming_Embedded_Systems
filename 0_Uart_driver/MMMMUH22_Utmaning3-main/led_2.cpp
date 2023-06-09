#include "led_2.hh"

// Constructor for LEDs
Led::Led()
{
	RCC->AHB1ENR |= LED_PORT_CLOCK; // Enable the clock for the LED port (GPIOB)


	while (1)
	{
		LED_PORT->MODER |=LED_RED_MODE_BIT; // Set MODER14 (pin that connects to the red LED) to general purpose output mode
		LED_PORT->ODR |= LED_RED_PIN; // Turn the red LED on by setting the corresponding bit in the output data register for the LED port to 1
		delay(420);

		LED_PORT->MODER |=LED_GREEN_MODE_BIT; // Set MODER12 (pin that connects to the green LED) to general purpose output mode
		LED_PORT->ODR |= LED_GREEN_PIN; // Turn the green LED on by setting the corresponding bit in the output data register for the LED port to 1
		delay(420);

		LED_PORT->MODER |=LED_YELLOW_MODE_BIT; // Set MODER14 (pin that connects to the yellow LED) to general purpose output mode
		LED_PORT->ODR |= LED_YELLOW_PIN; // Turn the red LED on by setting the corresponding bit in the output data register for the LED port to 1
		delay(420);

		LED_PORT->MODER |=LED_BLUE_MODE_BIT; // Set MODER12 (pin that connects to the blue LED) to general purpose output mode
		LED_PORT->ODR |= LED_BLUE_PIN; // Turn the green LED on by setting the corresponding bit in the output data register for the LED port to 1
		delay(420);


		LED_PORT->MODER |=LED_RED_MODE_BIT; // Set MODER14 (pin that connects to the red LED) to general purpose output mode
		LED_PORT->ODR &= ~LED_RED_PIN; // Turn the red LED off by setting the corresponding bit in the output data register for the LED port to 0
		delay(420);

		LED_PORT->MODER |=LED_GREEN_MODE_BIT; // Set MODER12 (pin that connects to the green LED) to general purpose output mode
		LED_PORT->ODR &= ~LED_GREEN_PIN; // Turn the green LED off by setting the corresponding bit in the output data register for the LED port to 0
		delay(420);

		LED_PORT->MODER |=LED_YELLOW_MODE_BIT; // Set MODER14 (pin that connects to the yellow LED) to general purpose output mode
		LED_PORT->ODR &= ~LED_YELLOW_PIN; // Turn the red LED off by setting the corresponding bit in the output data register for the LED port to 0
		delay(420);

		LED_PORT->MODER |=LED_BLUE_MODE_BIT; // Set MODER12 (pin that connects to the blue LED) to general purpose output mode
		LED_PORT->ODR &= ~LED_BLUE_PIN; // Turn the green LED off by setting the corresponding bit in the output data register for the LED port to 0
		delay(420);
	}
}
