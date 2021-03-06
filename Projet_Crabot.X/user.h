#ifndef _USER_H_
#define _USER_H_

/******************************************************************************/
/* User Level #define Macros                                                  */
/******************************************************************************/
#define led _LATA2

// ultrason : en RC4 // defini dans ultrason .h

/******************************************************************************/
/* System Level #define Macros                                                */
/******************************************************************************/

/* Microcontroller MIPs (FCY) */
#define SYS_FREQ        80000000UL
#define FCY             SYS_FREQ/2
#define FOSC            FCY


#define BAUDRATEAX12 57600
#define BRGVALAX12 ((FCY / BAUDRATEAX12 / 16) - 1)

#define BAUDRATERASPI	57600
#define BRGVALRASPI ((FCY / BAUDRATERASPI / 16) - 1)





/******************************************************************************/
/* System Function Prototypes                                                 */
/******************************************************************************/

/* Custom oscillator configuration funtions, reset source evaluation
functions, and other non-peripheral microcontroller initialization functions
go here. */

void ConfigureOscillator(void); /* Handles clock switching/osc initialization */
void InitTimers();
void Init_CN(void);
void writeStringToUART (const char* msg);
// initialize all things
void Init_All(int);




#endif // _USER_H_
