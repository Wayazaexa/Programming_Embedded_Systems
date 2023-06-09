#include "leds.hh"

Leds::rolling_colors()
{
	while(1)
	{
		led_r.setState(ON);
		delay(420);
		led_g.setState(ON);
		delay(420);
		led_y.setState(ON);
		delay(420);
		led_b.setState(ON);
		delay(420);

		led_r.setState(OFF);
		delay(420);
		led_g.setState(OFF);
		delay(420);
		led_y.setState(OFF);
		delay(420);
		led_b.setState(OFF);
		delay(420);
	}
}
