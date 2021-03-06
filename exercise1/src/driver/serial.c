#include "serial.h"

void init_dbgu();

int strlen(char *str) {
    int count = 0;
    char* walker = str;
    while(*walker != '\0') {
        count++;
        walker++;
    }
    return count;
}

/* Sendet ein Zeichen, ueber die serielle Leitung */
void serial_writechar(char chr) {
    while(!((*DBGU_SR) & TXRDY_BIT));
    *DBGU_THR = chr;
}

/* Sendet eine Zeichenkette, ueber die serielle Leitung */
void serial_write(char* str) {
    int i;
    init_dbgu();
    for(i = 0; i < strlen(str); i++)
        serial_writechar(str[i]);
}

/*  Function: init_dbgu
*   -------------------
*   Performs initialisation of the processor debug unit.
*/
void init_dbgu() {
    *DBGU_CR = TXEN_BIT;
    //*DBGU_MR = PARITY_BIT;
}
