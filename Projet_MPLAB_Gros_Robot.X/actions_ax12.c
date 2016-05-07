
#include <xc.h>
//#include <p33Fxxxx.h>      /* Includes device header file                     */
//#include <stdint.h>        /* Includes uint16_t definition                    */
//#include <stdbool.h>       /* Includes true/false definition                  */
#include <stdio.h>
//#include <uart.h>
#include <delay.h>

#include "main.h"


#define maxtork_claw 650
#define maxspeed_claw 800
#define delay_min_ax 30

/******************************************************************************/
/*************************** Arm Specification ********************************/
/******************************************************************************/

// PIN TEAM = COTE D'EQUIPE VIOLET !!

/******************************************************************************/
/****************************** Init Position *********************************/
/******************************************************************************/

volatile int Num_Action_Done = 0;
volatile int Num_Action_ToDo = 0;
volatile char Tab_Actions_ToDo [NUM_ACTIONS_BUFFER] = {0};



void Add_Action_AX12(char Action_ToDo)
{
    int num = Num_Action_ToDo;
    num++;
    if (num == NUM_ACTIONS_BUFFER) {
        num = 0;
    }
    Tab_Actions_ToDo[num] = Action_ToDo;
    Num_Action_ToDo = num;
}

void Faire_Actions_AX12(void)
{
    char Action_ToDo;
    
    if (Num_Action_Done != Num_Action_ToDo) {
        Num_Action_Done++;
        if (Num_Action_Done == NUM_ACTIONS_BUFFER) {
            Num_Action_Done = 0;
        }
        Action_ToDo = Tab_Actions_ToDo[Num_Action_Done];
        // on a le droit de faire des actions apr�s le delais que si c'est Funny action 
        if (!Delay_90_Over || (Action_ToDo == AX12_FUNNY_ACTION)) {
            switch (Action_ToDo)
            {
                case AX12_INIT_AX12 :
                    Init_ax12();
                    break;
                case AX12_DEPLOY_FISH_AV :
                    Deploy_fish_Av();
                    break;
                case AX12_DEPLOY_FISH_AR :
                    Deploy_fish_Ar();
                    break;
                case AX12_DEPLOY_FISH :
                    Deploy_fish();
                    break;
                case AX12_MOVEUP_FISH_AV:
                    Moveup_fish_Av();
                    break;
                case AX12_MOVEUP_FISH_AR:
                    Moveup_fish_Ar();
                    break;
                case AX12_RLZ_FISH_AV:
                    Rlz_fish_Av();
                    break;
                case AX12_RLZ_FISH_AR:
                    Rlz_fish_Ar();
                    break;
                case AX12_RLZ_FISH:
                    Rlz_fish();
                    break;
                case AX12_OPEN_BRAS:
                    Open_bras();
                    break;
                case AX12_CATCH_BRAS:
                    Catch_bras();
                    break;
                case AX12_OPENFULL_BRAS:
                    Openfull_bras();
                    break;
                case AX12_CLOSE_BRAS:
                    Close_bras();
                    break;
                case AX12_FUNNY_ACTION:
                    Funny_action();
                    break;
                default :
                    printf("$FAIL;");
                    break;
            }
        }
    }
}

void Init_ax12() {

    PutAX(Fish_AvG, 	AX_TORQUE_LIMIT, maxtork_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_AvD, 	AX_TORQUE_LIMIT, maxtork_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArG, 	AX_TORQUE_LIMIT, maxtork_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArD, 	AX_TORQUE_LIMIT, maxtork_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_AvG, 	AX_TORQUE_LIMIT, 850);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_AvD, 	AX_TORQUE_LIMIT, 850);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArG, 	AX_TORQUE_LIMIT, 850);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArD, 	AX_TORQUE_LIMIT, 850);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_G, 	AX_TORQUE_LIMIT, 1000);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_C, 	AX_TORQUE_LIMIT, 1000);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_D, 	AX_TORQUE_LIMIT, 1000);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_parasol, AX_TORQUE_LIMIT, maxtork_claw);
                        __delay_ms(delay_min_ax);

    PutAX(Fish_AvG, 	AX_MOVING_SPEED, 70);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_AvD, 	AX_MOVING_SPEED, 70);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArG, 	AX_MOVING_SPEED, 70);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArD, 	AX_MOVING_SPEED, 70);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_AvG, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_AvD, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArG, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArD, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_G, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_C, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_D, 	AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_parasol, AX_MOVING_SPEED, maxspeed_claw);
                        __delay_ms(delay_min_ax);

                     
    PutAX(Magnet_AvG,       AX_GOAL_POSITION, 195);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArG,       AX_GOAL_POSITION, 812);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_AvD,       AX_GOAL_POSITION, 830);
                        __delay_ms(delay_min_ax);
    PutAX(Magnet_ArD,       AX_GOAL_POSITION, 820);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_AvG,         AX_GOAL_POSITION, 527);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArG,         AX_GOAL_POSITION, 195);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_AvD,         AX_GOAL_POSITION, 492);
                        __delay_ms(delay_min_ax);
    PutAX(Fish_ArD,         AX_GOAL_POSITION, 834);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_G,           AX_GOAL_POSITION, 830);
                        __delay_ms(delay_min_ax);
    if(!PIN_TEAM)       // VERT
    {
        PutAX(Bras_C,           AX_GOAL_POSITION, 120);
    } else {            // VIOLET
        PutAX(Bras_C,           AX_GOAL_POSITION, 670);
    }
                        __delay_ms(delay_min_ax);
    PutAX(Bras_D,           AX_GOAL_POSITION, 200);
                        __delay_ms(delay_min_ax);
    PutAX(Bras_parasol,     AX_GOAL_POSITION, 470);
                        __delay_ms(delay_min_ax);

}

// PIN TEAM = 1 pour violet, 0 pour vert

 void Deploy_fish_Av(void)		// D�ploie le bras de p�che Avant.
 {
    if(!PIN_TEAM)       // VERT
    {    
        PutAX(Fish_AvG,     AX_GOAL_POSITION,210);
    }
    else                // VIOLET
    {
        PutAX(Fish_AvD,     AX_GOAL_POSITION,810);
    }
    __delay_ms(2000);
 }

 void Deploy_fish_Ar(void)		// D�ploie le bras de p�che Arriere.
 {
    if(!PIN_TEAM)           // VERT
    {    
        PutAX(Fish_ArG,     AX_GOAL_POSITION,510);
    }
    else                    // VIOLET
    {    
        PutAX(Fish_ArD,     AX_GOAL_POSITION,510);
    }
    __delay_ms(2000);
 }

 void Deploy_fish(void)
 {
    if(!PIN_TEAM)       // C�t� VERT
    {   
        PutAX(Fish_AvG,         AX_MOVING_SPEED, 512);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArG,         AX_MOVING_SPEED, 512);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_AvG,     AX_GOAL_POSITION,225);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArG,     AX_GOAL_POSITION,495);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_AvG, 	AX_MOVING_SPEED, 70);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArG,         AX_MOVING_SPEED, 70);
    }
    else                // VIOLET
    {
        PutAX(Fish_AvD,         AX_MOVING_SPEED, 512);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArD,         AX_MOVING_SPEED, 512);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_AvD,     AX_GOAL_POSITION,780);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArD,     AX_GOAL_POSITION,540);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_AvD, 	AX_MOVING_SPEED, 70);
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArD, 	AX_MOVING_SPEED, 70);
    }
    __delay_ms(2000);
    SendDone();
 }

 void Moveup_fish_Av(void)		// Releve legerement le bras de p�che Avant.
 {
    if(!PIN_TEAM)               // VERT
    {    
        PutAX(Fish_AvG,     AX_GOAL_POSITION,390);
    }
    else                        // VIOLET
    {    
        PutAX(Fish_AvD,     AX_GOAL_POSITION,620);
    }
    __delay_ms(delay_min_ax);
 }

 void Moveup_fish_Ar(void)		// Releve legerement le bras de p�che Arriere.
 {
    if(!PIN_TEAM)           // VERT
    {
        PutAX(Fish_ArG,AX_GOAL_POSITION,327);
    }
    else                    // VIOLET
    {
        PutAX(Fish_ArD,AX_GOAL_POSITION,713);
    }
    __delay_ms(delay_min_ax);
}

 void Rlz_fish_Av(void)		// Leve le bras d'aimants Avant.
 {  
    if(!PIN_TEAM)           // VERT
    {
        PutAX(Fish_AvG,         AX_GOAL_POSITION,220);
        __delay_ms(1500);
	PutAX(Magnet_AvG,       AX_GOAL_POSITION,512);	// L�chez les poissons !!!!
        __delay_ms(500);
	PutAX(Magnet_AvG, 	AX_GOAL_POSITION, 195); // Rangement du bras a aimants.
                                __delay_ms(delay_min_ax);
        PutAX(Fish_AvG, 	AX_GOAL_POSITION, 527); // Rangement du bras de p�che.
    }
    else                    // VIOLET
    {
        PutAX(Fish_AvD,         AX_GOAL_POSITION,800);
        __delay_ms(1500);
	PutAX(Magnet_AvD,       AX_GOAL_POSITION,512);	// L�chez les poissons !!!!
	__delay_ms(500);
	PutAX(Magnet_AvD, 	AX_GOAL_POSITION, 830); // Rangement du bras a aimants.
                                __delay_ms(delay_min_ax);
        PutAX(Fish_AvD, 	AX_GOAL_POSITION, 492); // Rangement du bras de p�che.
	}
    __delay_ms(delay_min_ax);
    SendDone();
 }

 void Rlz_fish_Ar(void)		// Leve le bras d'aimants Avant.
 {
    if(!PIN_TEAM)       // VERT
	{
        PutAX(Fish_ArG,         AX_GOAL_POSITION, 500);
        __delay_ms(1500);
        PutAX(Magnet_ArG,       AX_GOAL_POSITION, 712);	// L�chez les poissons !!!!
        __delay_ms(500);
        PutAX(Magnet_ArG, 	AX_GOAL_POSITION, 812); // Rangement du bras a aimants.
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArG, 	AX_GOAL_POSITION, 195); // Rangement du bras de p�che.
	}
    else                // VIOLET
    {
        PutAX(Fish_ArD,         AX_GOAL_POSITION, 520);
        __delay_ms(1500);
	PutAX(Magnet_ArD,       AX_GOAL_POSITION, 700);	// L�chez les poissons !!!!
	__delay_ms(500);
	PutAX(Magnet_ArD, 	AX_GOAL_POSITION, 820); // Rangement du bras a aimants.
                            __delay_ms(delay_min_ax);
        PutAX(Fish_ArD, 	AX_GOAL_POSITION, 834); // Rangement du bras de p�che.
	}
    __delay_ms(delay_min_ax);
    SendDone();
 }
 
 void Rlz_fish(void)		// Leve le bras d'aimants Avant.
 {  
    if(!PIN_TEAM)       // VERT
    {
        PutAX(Fish_AvG,         AX_GOAL_POSITION,220);           // Placement des bras
                                __delay_ms(delay_min_ax);
        PutAX(Fish_ArG,         AX_GOAL_POSITION, 500);
        __delay_ms(1500);
	PutAX(Magnet_AvG,       AX_GOAL_POSITION, 395);	// L�chez les poissons !!!!
                                __delay_ms(delay_min_ax);
        PutAX(Magnet_ArG,       AX_GOAL_POSITION, 612);
	__delay_ms(400);        
        PutAX(Fish_AvG, 	AX_GOAL_POSITION, 527); // Rangement du bras de p�che.
                                __delay_ms(delay_min_ax);
        PutAX(Fish_ArG, 	AX_GOAL_POSITION, 195);
        __delay_ms(200);                                // On laisse les bras se lever un peu avant de re-baisser les magnets, pour ne pas attraper � nouveau les poissons.
	PutAX(Magnet_AvG, 	AX_GOAL_POSITION, 195); // Rangement du bras a aimants.
                                __delay_ms(delay_min_ax);
        PutAX(Magnet_ArG, 	AX_GOAL_POSITION, 812);
                                __delay_ms(delay_min_ax);

    }
    else                // VIOLET
    {
        PutAX(Fish_AvD,         AX_GOAL_POSITION,780);  // Placement des bras
                                __delay_ms(delay_min_ax);
        PutAX(Fish_ArD,         AX_GOAL_POSITION, 540);
        __delay_ms(1500);
	PutAX(Magnet_AvD,       AX_GOAL_POSITION,630);	// L�chez les poissons !!!!
                                __delay_ms(delay_min_ax);
        PutAX(Magnet_ArD,       AX_GOAL_POSITION, 612);
	__delay_ms(400);
        PutAX(Fish_AvD, 	AX_GOAL_POSITION, 492); // Rangement du bras de p�che.
                                __delay_ms(delay_min_ax);
        PutAX(Fish_ArD, 	AX_GOAL_POSITION, 834);
        __delay_ms(200);
	PutAX(Magnet_AvD, 	AX_GOAL_POSITION, 830); // Rangement du bras a aimants.
                                __delay_ms(delay_min_ax);
        PutAX(Magnet_ArD, 	AX_GOAL_POSITION, 820);
    }
    __delay_ms(delay_min_ax);
    SendDone();
 }

void Open_bras(void)
{
    if(!PIN_TEAM)
	{
        //PutAX(Bras_D,AX_GOAL_POSITION,512);
        PutAX(Bras_D,   AX_GOAL_POSITION,585);
                        __delay_ms(delay_min_ax);
        PutAX(Bras_C,   AX_GOAL_POSITION,350); //reouvre
    }
    else
    {
        //PutAX(Bras_G,AX_GOAL_POSITION,512);
        PutAX(Bras_G,   AX_GOAL_POSITION,435);
                        __delay_ms(delay_min_ax);
        PutAX(Bras_C,   AX_GOAL_POSITION,1000); //reouvre
    }
    __delay_ms(delay_min_ax);
}

void Openfull_bras (void) 
{	// Ouverture � 180� des bras pour fermer les portes.
    if(!PIN_TEAM)
    {
        PutAX(Bras_D,       AX_GOAL_POSITION,795);  //cot� vert
                        __delay_ms(delay_min_ax);
        PutAX(Bras_C,       AX_GOAL_POSITION,120);
                        __delay_ms(delay_min_ax);
        PutAX(Bras_G,       AX_GOAL_POSITION,225);
                        __delay_ms(delay_min_ax);
    } else {
        PutAX(Bras_D,       AX_GOAL_POSITION,795); //cot� violet
                        __delay_ms(delay_min_ax);
        PutAX(Bras_C,       AX_GOAL_POSITION,670);
                        __delay_ms(delay_min_ax);
        PutAX(Bras_G,       AX_GOAL_POSITION,225);
                        __delay_ms(delay_min_ax);        
    }
}

void Catch_bras(void)
{ // Resserrage des bras contre les blocs de sable.
    if(!PIN_TEAM)
    {
        PutAX(Bras_C,       AX_GOAL_POSITION,365); //cot� vert
                            __delay_ms(500);
        PutAX(Bras_D,       AX_GOAL_POSITION,462);
                            __delay_ms(500);
        PutAX(Bras_C,       AX_GOAL_POSITION,400);
    }
    else
    {
        PutAX(Bras_C,       AX_GOAL_POSITION,960); //cot� violet
                            __delay_ms(500);
        PutAX(Bras_G,       AX_GOAL_POSITION,560);
                            __delay_ms(500);
        PutAX(Bras_C,       AX_GOAL_POSITION,930);
    }
    __delay_ms(300);
    SendDone();
}

void Close_bras(void)
{ // Rangement des bras.
    if(!PIN_TEAM)
    {
        PutAX(Bras_G, 	AX_GOAL_POSITION, 830);         //cot� vert
                            __delay_ms(delay_min_ax);
        PutAX(Bras_D, 	AX_GOAL_POSITION, 200);
                            __delay_ms(400);
        PutAX(Bras_C, 	AX_GOAL_POSITION, 120);
                            __delay_ms(delay_min_ax);
    }
    else
    {
        PutAX(Bras_G, 	AX_GOAL_POSITION, 830);         //cot� violet
                            __delay_ms(delay_min_ax);
        PutAX(Bras_D, 	AX_GOAL_POSITION, 200);
                            __delay_ms(400);
        PutAX(Bras_C, 	AX_GOAL_POSITION, 670);
                            __delay_ms(delay_min_ax);
    }
}

void Funny_action(void)
{ // D�ploiement du bras pour tendre le 'parasol'.
    PutAX(Bras_parasol,     AX_GOAL_POSITION, 207);
                            __delay_ms(delay_min_ax);
}

/******************************************************************************/