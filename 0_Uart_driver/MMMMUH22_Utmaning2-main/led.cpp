#include "led.hh"

// Constructor for LEDs
Led::Led(LedColor_Type _color, LedState_Type _state)
{
	this->color  = _color; // Set the color of the LED type to the color received as argument
	this->state  = _state; // Set the state of the LED type to the state received as argument

	RCC->AHB1ENR |= LED_PORT_CLOCK; // Enable the clock for the LED port (GPIOB)

	switch(_color)
	{

		case RED: // If this is a red LED
			LED_PORT->MODER |=LED_RED_MODE_BIT; // Set MODER14 (pin that connects to the red LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the red LED should be on
				LED_PORT->ODR |= LED_RED_PIN; // Turn the red LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The RED Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the red LED should be off
				LED_PORT->ODR &= ~LED_RED_PIN; // Turn the red LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The RED Led is set OFF \n\r"); // Print what happened
			}
		break;

		case YELLOW: // If this is a yellow LED
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT; // Set MODER13 (pin that connects to the yellow LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the yellow LED should be on
				LED_PORT->ODR |= LED_YELLOW_PIN; // Turn the yellow LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The YELLOW Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the yellow LED should be off
				LED_PORT->ODR &= ~LED_YELLOW_PIN; // Turn the yellow LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The YELLOW Led is set OFF \n\r"); // Print what happened
			}
		break;

		case BLUE: // If this is a blue LED
			LED_PORT->MODER |=LED_BLUE_MODE_BIT; // Set MODER15 (pin that connects to the blue LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the blue LED should be on
				LED_PORT->ODR |= LED_BLUE_PIN; // Turn the blue LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The BLUE Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the blue LED should be off
				LED_PORT->ODR &= ~LED_BLUE_PIN; // Turn the blue LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The BLUE Led is set OFF \n\r"); // Print what happened
			}
		break;

		case GREEN: // If this is a green LED
			LED_PORT->MODER |=LED_GREEN_MODE_BIT; // Set MODER12 (pin that connects to the green LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the green LED should be on
				LED_PORT->ODR |= LED_GREEN_PIN; // Turn the green LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The GREEN Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the green LED should be off
				LED_PORT->ODR &= ~LED_GREEN_PIN; // Turn the green LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The GREEN Led is set OFF \n\r"); // Print what happened
			}
		break;

	}
}

// Setter for the state of a LED
// Does exactly the same thing as the constructor, except setting the color and enabling the clock
void Led::setState(LedState_Type _state)
{
	this->state  = _state; // Set the state of the LED type to the state received as argument

	switch(this->color)
	{

		case RED: // If this is a red LED
			LED_PORT->MODER |=LED_RED_MODE_BIT; // Set MODER14 (pin that connects to the red LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the red LED should be on
				LED_PORT->ODR |= LED_RED_PIN; // Turn the red LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The RED Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the red LED should be off
				LED_PORT->ODR &= ~LED_RED_PIN; // Turn the red LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The RED Led is set OFF \n\r"); // Print what happened
			}
		break;

		case YELLOW: // If this is a yellow LED
			LED_PORT->MODER |=LED_YELLOW_MODE_BIT; // Set MODER13 (pin that connects to the yellow LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the yellow LED should be on
				LED_PORT->ODR |= LED_YELLOW_PIN; // Turn the yellow LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The YELLOW Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the yellow LED should be off
				LED_PORT->ODR &= ~LED_YELLOW_PIN; // Turn the yellow LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The YELLOW Led is set OFF \n\r"); // Print what happened
			}
		break;

		case BLUE: // If this is a blue LED
			LED_PORT->MODER |=LED_BLUE_MODE_BIT; // Set MODER15 (pin that connects to the blue LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the blue LED should be on
				LED_PORT->ODR |= LED_BLUE_PIN; // Turn the blue LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The BLUE Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the blue LED should be off
				LED_PORT->ODR &= ~LED_BLUE_PIN; // Turn the blue LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The BLUE Led is set OFF \n\r"); // Print what happened
			}
		break;

		case GREEN: // If this is a green LED
			LED_PORT->MODER |=LED_GREEN_MODE_BIT; // Set MODER12 (pin that connects to the green LED) to general purpose output mode
			if (this->state  == ON)
			{ // If the green LED should be on
				LED_PORT->ODR |= LED_GREEN_PIN; // Turn the green LED on by setting the corresponding bit in the output data register for the LED port to 1
				//printf("The GREEN Led is set ON \n\r"); // Print what happened
			}
			else
			{ // If the green LED should be off
				LED_PORT->ODR &= ~LED_GREEN_PIN; // Turn the green LED off by setting the corresponding bit in the output data register for the LED port to 0
				//printf("The GREEN Led is set OFF \n\r"); // Print what happened
			}
		break;

	}
}

// Getter for the state of a LED
LedState_Type Led::getState() const{

	/*switch(this->color){

		case RED: // If the LED is red
			printf("The RED Led is cureently %d \n\r", this->state); // Print the state of the red LED
		break;

		case GREEN: // If the LED is green
			printf("The GREEN Led is cureently %d \n\r", this->state); // Print the state of the green LED
		break;

		case BLUE: // If the LED is blue
			printf("The BLUE Led is cureently %d\n\r", this->state); // Print the state of the blue LED
		break;

		case YELLOW: // If the LED is yellow
			printf("The YELLOW Led is cureently  %d \n\r", this->state); // Print the state of the yellow LED
		break;
	}*/

	return this->state;
}
