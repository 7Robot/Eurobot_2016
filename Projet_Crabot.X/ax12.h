/*
 *  ax12.h - C18 library to use the AX-12 servomotor (Dynamixel Series) from
 *  Robotis on the PIC18F family from Microchip.
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#ifndef _AX12_H
#define _AX12_H

#define PIN_REMAPABLE_AX12_OUT          _RP10R
#define PIN_REMAPABLE_AX12_IN           10
#define TRIS_PIN_REMAPABLE_AX12         _TRISB10
#define OPEN_DRAIN_PIN_REMAPABLE_AX12   _ODCB10


//#define DOUBLE_COMMANDE_AX12

#define TEST_RECEPTION_AX12


typedef unsigned char byte;

// EEPROM Registers
#define AX_MODEL_NUMBER             0
#define AX_VERSION                  2
#define AX_ID                       3
#define AX_BAUD_RATE                4
#define AX_RETURN_DELAY_TIME        5
#define AX_CW_ANGLE_LIMIT           6
#define AX_CCW_ANGLE_LIMIT          8
#define AX_RESERVED_1               10
#define AX_LIMIT_TEMPERATURE        11
#define AX_DOWN_LIMIT_VOLTAGE       12
#define AX_UP_LIMIT_VOLTAGE         13
#define AX_MAX_TORQUE               14
#define AX_RETURN_LEVEL             16
#define AX_ALARM_LED                17
#define AX_ALARM_SHUTDOWN           18
#define AX_RESERVED_2               19
#define AX_DOWN_CALIBRATION         20
#define AX_UP_CALIBRATION           22

// RAM Registers
#define AX_TORQUE_ENABLE            24
#define AX_LED                      25
#define AX_CW_COMPLIANCE_MARGIN     26
#define AX_CCW_COMPLIANCE_MARGIN    27
#define AX_CW_COMPLIANCE_SLOPE      28
#define AX_CCW_COMPLIANCE_SLOPE     29
#define AX_GOAL_POSITION            30
#define AX_MOVING_SPEED             32
#define AX_TORQUE_LIMIT             34
#define AX_PRESENT_POSITION         36
#define AX_PRESENT_SPEED            38
#define AX_PRESENT_LOAD             40
#define AX_PRESENT_VOLTAGE          42
#define AX_PRESENT_TEMPERATURE      43
#define AX_REGISTERED_INSTRUCTION   44
#define AX_PAUSE_TIME               45
#define AX_MOVING                   46
#define AX_LOCK                     47
#define AX_PUNCH                    48

// Status Return Levels
#define AX_RETURN_NONE              0
#define AX_RETURN_READ              1
#define AX_RETURN_ALL               2

// Instruction Set
#define AX_INST_PING                1
#define AX_INST_READ_DATA           2
#define AX_INST_WRITE_DATA          3
#define AX_INST_REG_WRITE           4
#define AX_INST_ACTION              5
#define AX_INST_RESET               6
#define AX_INST_SYNC_WRITE          131

// Broadcast ID
#define AX_GAUCHE                   3
#define AX_DROIT                    2
#define AX_BROADCAST               254

/*
 * Stucture to decode error fields used in the return status, address17 and
 * address18, where each bit has a different meaning.
 */

#define AX12_CMD_NB_MAX_TRY_SEND 5

typedef struct
{
    uint8_t AX12_Addr;
    uint8_t Command;
    uint8_t Reg_Addr;
    uint8_t *Data;
    uint8_t Nb_Data;
    uint8_t *Status;
    uint8_t *Done;
} AX12_Command;


void Init_Com_AX12 (void);


void Set_AX12_TX(void);
void Set_AX12_RX(void);


void AX12_Every_ms (void);

void Add_AX12_Cmd (uint8_t AX12_Addr, uint8_t Command, uint8_t Reg_Addr, uint8_t *Data, uint8_t Nb_Data, uint8_t *Status, uint8_t *Done);


byte RegisterLenAX(byte address);

void Send_AX(uint8_t id, uint8_t Reg, uint16_t Data);



#endif /* _AX12_H */