/*
 * Ram.c
 *
 *  Created on: 6 feb. 2019
 *      Author: Jorge Lopez
 */

#include "Ram.h"

uint16_t  u16TimeSec;
uint16_t  u16TimePerSec1ms;


uint16_t u16ADC_Data;
uint16_t u16ADC_FilterdData;
uint8_t U8DutyCycle;

uint64_t capture_overflow;
uint32_t capture_counter;
uint64_t time_captured;

char value;
char g_value [5];

volatile union Ubyte_def        u8FlagsVar;
/*
#define    u8Flags              u8FlagsVar.Ubyte
#define    bf_SystemTickTrue     u8FlagsVar.Ubit.b0
*/


void SR_InitRam(void)
{
    u16TimeSec = 0;
    u16TimePerSec1ms = C_TICK_PER_SEC;
    //g_value [5]    = "000";

    capture_overflow = 0;
    capture_counter = 0;
    time_captured = 0;

}
