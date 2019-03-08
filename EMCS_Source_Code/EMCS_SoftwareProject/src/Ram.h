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

struct  Ubit_def
  {
    uint8_t  b0:1;
    uint8_t  b1:1;
    uint8_t  b2:1;
    uint8_t  b3:1;
    uint8_t  b4:1;
    uint8_t  b5:1;
    uint8_t  b6:1;
    uint8_t  b7:1;
  };
union   Ubyte_def
  {
    struct  Ubit_def Ubit;
    uint8_t      Ubyte;
  };


//--------------------------------------------------------------------
//            Global Definitions
//--------------------------------------------------------------------

#define C_TRUE      1
#define C_FALSE     0

#define C_TICK_PER_SEC  500

#define C_FILTER_ORDER  15

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
extern uint8_t U8DutyCycle;

extern char value;
extern char g_value [5];

extern uint64_t capture_overflow;
extern uint32_t capture_counter;
extern uint64_t time_captured;
extern uint64_t u64TimeCaptured_ns;
extern uint32_t u32TimeCaptured_us;
extern uint64_t time_captured_s;
extern uint64_t time_captured_ms;

extern uint32_t u32SpeedInst;




extern volatile union Ubyte_def        u8FlagsVar;
#define    u8Flags              u8FlagsVar.Ubyte
#define    bf_SystemTickTrue     u8FlagsVar.Ubit.b0


extern void SR_InitRam(void);


#endif /* RAM_H_ */
