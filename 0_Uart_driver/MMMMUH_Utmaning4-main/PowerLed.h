#ifndef	_POWERLED_H
#define _POWERLED_H

#include "led.h"

typedef uint8_t led_elec_type; // Define elec type, indicates electrical type
typedef uint8_t led_dim_type; // Define dim type, indicates diameter type


typedef  enum{
	CURR_LOW		= 10,   /*10mA*/
	CURR_NORMAL 	= 20,
	CURR_HIGH		= 35,
	CURR_VERY_HIGH 	= 60


}LedCurrent_Type; // Declaration of LedCurrent type, indicates how much current the LED [requires or can handle],
				  // useful for making sure the LED gets enough current

typedef enum{
	DIAM_2MM = 2,  /*2mm*/
	DIAM_5MM = 5,
	DIAM_7MM = 7

}LedDiamter_Type; // Declaration of LedDiameter type, indicates the diameter of the LED, useful for making sure there's enough room for the LED

typedef enum{
	VOL_LOW    = 3, /*3 volts*/
	VOL_NORMAL = 5,
	VOL_HIGH	 = 9

}LedVoltage_Type; // Declaration of LedVoltage type, indicates how much voltage the LED draws, useful(-ish) when calculating the device's overall power draw


typedef struct{
	Led_Type 		 super; // PowerLed_Type inherits color information from the Led_Type
	LedDiamter_Type  diameter;
	LedCurrent_Type  current;
	LedVoltage_Type  voltage;

}PowerLed_Type; // Declaration of PowerLed type, contains all the information about the LED.


void PowerLed_ctor(PowerLed_Type * const me,
				   LedColor_Type   _color,
				   LedState_Type	_state,
				   LedDiamter_Type  _diameter,
				   LedCurrent_Type   _current,
				   LedVoltage_Type  _voltage); // Declaration of the constructor for PowerLed

// Setters
void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type  _current );
void PowerLed_setDiameter(PowerLed_Type * const me, LedDiamter_Type _diameter);
void PowerLed_setVoltage(PowerLed_Type *const me, LedVoltage_Type _voltage);

led_elec_type PowerLed_computePower(PowerLed_Type * const me); // Declaration of function that calculates power draw
// Getters
led_elec_type PowerLed_getCurrent(PowerLed_Type * const me);
led_elec_type PowerLed_getDiameter(PowerLed_Type * const me);
led_elec_type PowerLed_getVoltage(PowerLed_Type * const me);

#endif
