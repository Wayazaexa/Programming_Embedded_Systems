#include "PowerLed.h"

void PowerLed_ctor(PowerLed_Type * const me,
				   LedColor_Type   _color,
				   LedState_Type	_state,
				   LedDiamter_Type  _diameter,
				   LedCurrent_Type   _current,
				   LedVoltage_Type  _voltage){ // Definition of PowerLed's constructor


	Led_ctor(&me->super,_color,_state); // Sets color and state via the constructor of the inherited Led_Type
	me->diameter  = _diameter;
	me->voltage   = _voltage;
	me->current    = _current;

}

void PowerLed_setCurrent(PowerLed_Type * const me,LedCurrent_Type  _current ){ // Sets current

	me->current = _current;
}

void PowerLed_setDiameter(PowerLed_Type * const me, LedDiamter_Type _diameter){ // Sets diameter

	me->diameter = _diameter;
}

void PowerLed_setVoltage(PowerLed_Type *const me, LedVoltage_Type _voltage){ // Sets voltage

	me->voltage = _voltage;
}


led_elec_type PowerLed_computePower(PowerLed_Type * const me){ // Calculates power draw and returns the result

	return(me->current * me->voltage);
}


led_elec_type PowerLed_getCurrent(PowerLed_Type * const me){ // Gets current

	return me->current;
}

led_elec_type PowerLed_getDiameter(PowerLed_Type * const me){ // Gets diameter (should probably use led_dim_type for readability, but they're both uint8_t)

	return me->diameter;
}


led_elec_type PowerLed_getVoltage(PowerLed_Type * const me){ // Gets voltage

	return me->voltage;
}
