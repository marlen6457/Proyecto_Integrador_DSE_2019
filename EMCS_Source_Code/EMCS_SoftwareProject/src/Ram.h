/*
 * Ram.h
 *
 *  Created on: 6 feb. 2019
 *      Author: Jorge Lopez
 */

#ifndef RAM_H_
#define RAM_H_

#include "main_thread.h"


//--------------------------------------------------------------------
//             Structure Definitions
//--------------------------------------------------------------------



//--------------------------------------------------------------------
//            Global Definitions
//--------------------------------------------------------------------

#define C_TRUE      1
#define C_FALSE     0

#define C_TICK_PER_SEC  500

#define C_FILTER_ORDER      15

/* Definition Setpoint */
#define C_STEP_SETPOINT_DESIRED      (100)
#define C_STEP_ADC_DESIRED           (8)

/* Definition Input Capture*/
#define BIT_32 (0x100000000U)                   // MAX COUNTS

#define TIMER_SECOND            (1000000000U)
#define TIMER_MILLISECOND       (1000000U)
#define TIMER_MICROSECOND       (1000U)

#define MICRO_SECONDS_IN_A_MINUTE   60000000

#define MAGNET_POLES        4
#define SCALED_FACTOR       1000


//--------------------------------------------------------------------
//             Global Variable
//--------------------------------------------------------------------

extern uint16_t  u16TimeSec;
extern uint16_t  u16TimePerSec1ms;

extern uint16_t u16ADC_Data;
extern uint16_t u16ADC_FilterdData;
extern uint8_t u8DutyCycleInst;
extern uint8_t u8DutyCycleReal;

extern uint16_t u16SetpointValue;
extern uint16_t u16SetpointValueold;

extern uint64_t capture_overflow;
extern uint32_t u32CaptureCounter;
extern uint64_t u64TimeCaptured;
extern uint64_t u64TimeCaptured_ns;
extern uint32_t u32TimeCaptured_us;
extern uint64_t time_captured_s;
extern uint64_t time_captured_ms;

extern uint32_t u32SpeedInst;
extern uint16_t u16SpeedInst;



//--------------------------------------------------------------------
//             Filter Variable
//--------------------------------------------------------------------

extern uint32_t u32VarAccumulator;
extern uint16_t u16RPMvalueAvg;
extern uint16_t u16InputValue;

//--------------------------------------------------------------------

extern volatile union Ubyte_def        u8FlagsVar;
#define    u8Flags              u8FlagsVar.Ubyte
#define    bf_SystemTickTrue     u8FlagsVar.Ubit.b0

//--------------------------------------------------------------------
//             Post message
//--------------------------------------------------------------------
extern const sf_message_post_cfg_t g_post_cfg;
extern const sf_message_acquire_cfg_t g_acquire_cfg;


//--------------------------------------------------------------------
//             Functions
//--------------------------------------------------------------------

extern void SR_InitRam(void);
extern void SR_GetSetpoit(void);

extern void SR_FilterRPM(uint16_t* lpu16Data, uint32_t* lpu32ShiftAdd, uint16_t* lpu16Result);
extern void SR_InitFilter(uint16_t lu16InputData);


extern void SR_RPMSignal_message(void);
extern void SR_Dutycycle_message(void);
extern void SR_SetpointADC_message(void);
extern uint16_t FN_GetSetpoitValue (uint16_t lu16ADCRaw);

#endif /* RAM_H_ */
