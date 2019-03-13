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
uint8_t u8DutyCycleInst;
uint8_t u8DutyCycleReal;

uint64_t capture_overflow;
uint32_t u32CaptureCounter;
uint64_t u64TimeCaptured;
uint64_t u64TimeCaptured_ns;
uint32_t u32TimeCaptured_us;

uint32_t u32SpeedInst;
uint16_t u16SpeedInst;

//--------------------------------------------------------------------
//             Filter Variable
//--------------------------------------------------------------------

uint32_t u32VarAccumulator;
uint16_t u16RPMvalueAvg;
uint16_t u16InputValue;

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
    u32CaptureCounter = 0;
    u64TimeCaptured = 0;

}
