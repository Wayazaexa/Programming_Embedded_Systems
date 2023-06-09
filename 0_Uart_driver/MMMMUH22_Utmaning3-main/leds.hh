#include "led.hh"

class Leds
{
private:
	Led led_r(RED, OFF);
	Led led_g(GREEN, OFF);
	Led led_y(YELLOW, OFF);
	Led led_b(BLUE, OFF);
public:
	Leds(){}
	rolling_colors();
};
