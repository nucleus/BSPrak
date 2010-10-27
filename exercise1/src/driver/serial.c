#include "serial.h"

void init_dbgu();

struct dbgUnit* dbgu = (struct dbgUnit*)DBGU_BASE; 

/* Sendet ein Zeichen, ueber die serielle Leitung */
void serial_writechar(char chr) {
    while(!((dbgu->sr) & TXRDY_BIT));
    dbgu->thr = chr;
}

/* Sendet eine Zeichenkette, ueber die serielle Leitung */
void serial_write(char* str) {
    while(*str){
        serial_writechar(*str);
        str++;
    }
}
