#include "leds.h"

struct pio_t *piob = (struct pio_t*) 0xFFFFF600;
struct pio_t *pioc = (struct pio_t*) 0xFFFFF800;


void leds_init()
{
 	piob->per = YELLOW_LED_BIT;
 	piob->oer = YELLOW_LED_BIT;

 	pioc->per = GREEN_LED_BIT | RED_LED_BIT;
 	pioc->oer = GREEN_LED_BIT | RED_LED_BIT;
}

void yellow_led(int bright)
{
 	if (bright) piob->sodr = YELLOW_LED_BIT;
 		else piob->codr = YELLOW_LED_BIT;
}

void red_led(int bright)
{
 	if (bright) pioc->sodr = RED_LED_BIT;
 		else pioc->codr = RED_LED_BIT;
}


void green_led(int bright)
{
 	if (bright) pioc->sodr = GREEN_LED_BIT;
 		else pioc->codr = GREEN_LED_BIT;
}
