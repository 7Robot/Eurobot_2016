#include <xc.h>



#include <stdint.h>          /* For uint16_t definition                       */
#include <stdbool.h>         /* For true/false definition                     */
#include <timer.h>

//#include "tests.h"
//#include "atp-asserv.h"
//#include "atp.h"

#include "main.h"

/******************************************************************************/
/* User Functions                                                             */
/******************************************************************************/

void ConfigureOscillator(void)
{
    // Configure PLL prescaler, PLL postscaler, PLL divisor
    PLLFBDbits.PLLDIV = 150;        // M=152
    CLKDIVbits.PLLPRE  = 5;         // N1=7
    CLKDIVbits.PLLPOST = 0;         // N2=2
    /* Fosc = M/(N1.N2)*Fin
     * Fin : 7.37MHz (quartz interne)
     * Fosc à 80 MHZ (ne doit pas dépasser 80 MHZ)
     * la solution la plus proche est 152*7.37/(7*2) = 80.017
     * attention, cela entraine donc une FCY et une FPériphériques à 40 MHZ
     */
    while (!OSCCONbits.LOCK);       // attente que la PLL soit lockée sur se nouvelle configuration.
}


// initialize all things
void Init_All(int callback){
    /* Configure the oscillator for the device */
    ConfigureOscillator();
    /* Initialize IO ports and peripherals */
    motion_free();
    InitTimers();
    Init_Communication_RasPi();
    
    __delay_ms(200);
    Init_PWM();
    Init_QEI();
    Init_IT_AX12();
    Gestion_IO_AU_Config_Init();
    __delay_ms(500);
    Init_ax12();
    //I2C_Init();
    InitSick_VBat();
    // Init_Ultrasons();  // surtout pas sur crabot malheureux !
    Init_Evitement();
    Position Pos = {0,0,0};
    set_position(Pos);
    motion_init(); // start asserv
    
    TRISAbits.TRISA9 = 1;
    
    
    

    if(callback) {
        SendDone();
    }
}

/*
void writeStringToUART (const char *msg)
{
    while(*msg)    {
        WriteUART1(*msg++);
    }
}
*/