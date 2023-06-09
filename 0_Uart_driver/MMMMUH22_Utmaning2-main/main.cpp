#include "led.hh"

int main(void)
{

	USART2_Init();

	Led led1(RED,OFF);
	Led led2(BLUE,ON);

	led1.getState();
	led2.getState();

	led1.setState(ON);

	while(1){}
}
