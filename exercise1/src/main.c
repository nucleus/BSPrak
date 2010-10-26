#include "driver/leds.h"
#include "driver/serial.h"

void busywait();

/* Hauptroutine wird von u-boot gerufen */
int main()
{
 	leds_init();

 	/* Endlosschleife */
 	while (1)
 	{
 		yellow_led(1);
 		serial_write("Hallo Welt\r\n");
 		yellow_led(0);
 		busywait();
 	}

}

/* Funktion verbraet sinnlos CPU-Takte */
void busywait()
{
 	int i;
 	for (i=0;i<1000000;i++) ;
}
