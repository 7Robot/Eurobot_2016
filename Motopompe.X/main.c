/*
 * File:   main.c
 * Author: Robot
 *
 * Created on 13 avril 2016, 09:48
 */

#include <xc.h>

#include "main.h"
#include "time.h"
//#include "i2c.h"

void main(void) {
    unsigned char data = 0x00;
    TRISA = 0;
    TRISC = 0b11111011;
    T2CON = 0b1001110; //On configure le port li� au Timer 2 (prescaler, postscaler,...).
    PR2 = 249;
    //OpenI2C (SLAVE_7, SLEW_OFF); //Slew rate disabled for 100 kHz mode

    while (1) {
        //SSPISR(&data);
        //printf("data %c", data);

    /*    LATA = 0b0001101;
        LATC = 0b00000100;
        
        time();
        
        LATA = 0;
        LATC = 0;
        
        time();*/
        
    }

}
/*
OpenI2C (SLAVE_7, SLEW_OFF); //Slew rate disabled for 100 kHz mode
//===================================================================
//Master : 
IdleI2C();                         // Wait until the bus is idle
//StartI2C();                         // Send START condition
IdleI2C();                         // Wait for the end of the START condition
//WriteI2C( slave_address & 0xfe );  // Send address with R/W cleared for write
//IdleI2C();                         // Wait for ACK
WriteI2C(0x01 );               // Write nth byte of data
IdleI2C();                         // Wait for ACK
StopI2C();       

*/
//Slave : 
/*
void SSPISR(char *data) {
    unsigned char temp;

    temp = SSPSTAT & 0x2d;
    if ((temp ^ 0x09) == 0x00) {            // 1: write operation, last byte was address
        //data = ReadI2C();
        // Do something with data, or just return
    } else if ((temp ^ 0x29) == 0x00) {     // 2: write operation, last byte was data
        data = ReadI2C();
        // Do something with data, or just return
    } else if ((temp ^ 0x0c) == 0x00) {     // 3: read operation, last byte was address
        // Do something, then write something to I2C
        WriteI2C(0x00);
    } else if ((temp ^ 0x2c) == 0x00) {     // 4: read operation, last byte was data
        // Do something, then write something to I2C
        WriteI2C(0x00);
    } else {                                // 5: slave logic reset by NACK from master
        // Don't do anything, clear a buffer, reset, whatever
    }
}
*/