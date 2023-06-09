#include "PowerLed.h"


PowerLed_Type pled1,pled2; // Declaration of 2 PowerLeds

// Declaration of 2 variables for power draw for 2 LEDs
led_elec_type led1_power;
led_elec_type led2_power;

int main(void){

	USART2_Init();

	PowerLed_ctor(&pled1,RED,ON,DIAM_5MM,CURR_NORMAL,VOL_NORMAL); // Defines a PowerLed for a red LED, turned on by default, 5mm diameter, 10mA, 5V
	PowerLed_ctor(&pled2,YELLOW,ON,DIAM_7MM,CURR_HIGH,VOL_NORMAL); // Defines a PowerLed for a yellow LED, turned on by default, 7mm diameter, 35mA, 5V

	led1_power = PowerLed_computePower(&pled1); // Calculates the power draw for pled1 and stores the result (50mW)
	led2_power = PowerLed_computePower(&pled2); // Calculates the power draw for pled2 and stores the result (175mW)


	while(1){

	}
}
