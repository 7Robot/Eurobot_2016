/*
 * Template dsPIC33F
 * Compiler : Microchip xC16
 * �C : 33FJ128MC804
 * Mars 2016
 *
 *    ______ _____      _           _
 *   |___  /| ___ \    | |         | |
 *      / / | |_/ /___ | |__   ___ | |_
 *     / /  |    // _ \| '_ \ / _ \| __|
 *    / /   | |\ \ (_) | |_) | (_) | |_
 *   /_/    |_| \_\___/|____/ \___/'\__|
 *			      7robot.fr
 */



/********Headers********/
#include <xc.h>
/******************************************************************************/
/* Configuration                                                             */
/******************************************************************************/


#include <stdint.h>        // Includes uint16_t definition
#include <stdio.h>         // Includes sprintf
#include <stdbool.h>       // Includes true/false definition
#include <math.h>
#include <stdlib.h>

#include "main.h"

void reglage_asserv(void);

volatile uint8_t VariableChangementAction;

int main(int argc, char** argv) {
    
    VariableChangementAction = 0;
    
    Speed SpeedBar;
    SpeedBar.v = 0.5;
    SpeedBar.vt = 0;
    
    Init_All(0);
    //reglage_asserv();

    while (1) {

        Gestion_IO_AU_Loop();
        
        int aleach;
        int aleadir;
        int aleabutter;
        
        motion_free();

        while (Get_US_Sector(0) != 0) {
            
            motion_speed(SpeedBar);
            
            aleach = rand() % 5000 + 1000;
            if (VariableChangementAction == aleach) {
                motion_free();
                aleadir = rand() % 360 + 15;
                motion_angle(aleadir);
                while (!motion_done());
                VariableChangementAction = 0;
            }
            
            aleabutter = rand() % 5000 + 1000;
            if (VariableChangementAction == 5000)
            {
                I_Can_Fly();
                I_Can_Fly();
                I_Can_Fly();
                I_Can_Fly();
                I_Can_Fly();
                VariableChangementAction = 0;
            }
            
            if (VariableChangementAction == 7000)
            {
                VariableChangementAction = 0;
            }
            
        }
        
        while (Get_US_Sector(0) != 1) {
            motion_free();
            aleadir = rand() % 360 + 15;
            motion_angle(aleadir);
            while(!motion_done());
        }
    }
        
}


void reglage_asserv(void)
{
    //while (PIN_LAISSE);
    Position Pos0, Pos1, Pos2, Pos3;
    Pos0.x = 0;
    Pos0.y = 0;
    Pos1.x = 0.5;
    Pos1.y = 0;
    Pos2.x = 0.5;
    Pos2.y = 0.5;
    Pos3.x = 0;
    Pos3.y = 0.5;
    
    motion_pos(Pos1);
    while(!motion_done());
    motion_pos(Pos2);
    while(!motion_done());
    motion_pos(Pos3);
    while(!motion_done());
    motion_pos(Pos0);
    while(!motion_done());
    
    motion_pos(Pos1);
    while(!motion_done());
    motion_pos(Pos2);
    while(!motion_done());
    motion_pos(Pos3);
    while(!motion_done());
    motion_pos(Pos0);
    while(!motion_done());
}

void Debug_Asserv_Start(void)
{
    while (PIN_LAISSE);
    Position pos1 = {0.40,0,0};
    Position pos2 = {0.40,0.40,0};
    motion_push(pos1,0.15);
    motion_push(pos2,0);
    //motion_speed(MOVE);
}

void Debug_Asserv_Start2(void)
{
    while (PIN_LAISSE);
    Position pos1 = {0.40,0,0};
    Position pos2 = {0.40,0.40,0};
    motion_pos(pos1);
    while(!motion_done());
    motion_pos(pos2);
    //motion_speed(MOVE);
}
