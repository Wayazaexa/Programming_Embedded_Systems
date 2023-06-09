#include "led.hh"

void main(void)
{

	USART2_Init();

	Led led1(RED, OFF);
	Led led2(GREEN, OFF);
	Led led3(YELLOW, OFF);
	Led led4(BLUE, OFF);

	while (1)
	{
		led1.setState(ON);
		delay(420);
		led2.setState(ON);
		delay(420);
		led3.setState(ON);
		delay(420);
		led4.setState(ON);
		delay(420);

		led1.setState(OFF);
		delay(420);
		led2.setState(OFF);
		delay(420);
		led3.setState(OFF);
		delay(420);
		led4.setState(OFF);
		delay(420);
	}

}
