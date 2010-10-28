#ifndef __SERIAL_
#define __SERIAL_

#define DBGU_BASE 0xFFFFF200

#define DBGU_CR (volatile unsigned int*)(DBGU_BASE)
#define DBGU_MR (volatile unsigned int*)(DBGU_BASE + 0x0004)
#define DBGU_SR (volatile unsigned int*)(DBGU_BASE + 0x0014)
#define DBGU_THR (volatile unsigned int*)(DBGU_BASE + 0x001C)

#define TXEN_BIT (1 << 6)
#define PARITY_BIT (1 << 11)
#define TXRDY_BIT (1 << 1)

struct dbgUnit{
    unsigned int cr;     //Control Register
    unsigned int mr;     //Mode Register
    unsigned int ier;    //Interrupt Enable Register
    unsigned int idr;    //Interrupt Disable Register
    unsigned int imr;    //Interrupt Mask Register
    volatile unsigned int sr;     //Status Register
    volatile unsigned int rhr;    //Receive Holding Register
    unsigned int thr;    //Transmit Holding Register
    unsigned int brgr;   //Baud Rate Generator Register
};

void serial_writechar(char chr);
void serial_write(char* str);


#endif
