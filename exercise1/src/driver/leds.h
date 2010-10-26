#ifndef __LEDS_
#define __LEDS_

struct pio_t {
 	unsigned int per;
 	unsigned int pdr;
 	unsigned int psr;
 	unsigned int __reserved0;
 	unsigned int oer;
 	unsigned int odr;
 	unsigned int osr;
 	unsigned int __reserved1;
 	unsigned int ifer;
 	unsigned int ifdr;
 	unsigned int ifsr;
 	unsigned int __reserved2;
 	unsigned int sodr;
 	unsigned int codr;
 	unsigned int odsr;
 	unsigned int pdsr;
 	unsigned int ier;
 	unsigned int idr;
 	unsigned int imr;
 	unsigned int isr;
 	unsigned int mder;
 	unsigned int mddr;
 	unsigned int mdsr;
 	unsigned int __reserved3;
 	unsigned int pudr;
 	unsigned int puer;
 	unsigned int pusr;
 	unsigned int __reserved4;
 	unsigned int asr;
 	unsigned int bsr;
 	unsigned int absr;
};

#define YELLOW_LED_BIT (1 << 27)
#define GREEN_LED_BIT (1 << 1)
#define RED_LED_BIT (1 << 0)

void leds_init();

void yellow_led(int bright);
void green_led(int bright);
void red_led(int bright);

#endif
