/*
 * Ram.c
 *
 *  Created on: 6 feb. 2019
 *      Author: Jorge Lopez
 */

#include "Ram.h"

//--------------------------------------------------------------------
//             Global Variable
//--------------------------------------------------------------------
 volatile bool bMotor;

uint16_t  u16TimeSec;
uint16_t  u16TimePerSec1ms;


uint16_t u16ADC_Data;
uint16_t u16ADC_FilterdData;
uint8_t u8DutyCycleInst;
uint8_t u8DutyCycleReal;

uint16_t u16SetpointValue;
uint16_t u16SetpointValueold;

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

//--------------------------------------------------------------------
//             PI Control Variable
//--------------------------------------------------------------------
int32_t    i32SpeedError2;
int32_t    i32SpeedError1;
int32_t    i32SpeedError0;

int64_t    i64Proporcial;
int64_t    i64Integral;

int64_t    i64CalcPI;

int64_t i64Calculation;

#define KP_LOW                ( 140)      // 0.140
#define KP_MID                ( 183)      // 0.183
#define KP_HIGH               ( 500)      // 0.500
#define KP_EXTRA_HIGH         (2000)      // 2.000

#define KI_LOW                (   3)      // 0.003
#define KI_MID                (   9)      // 0.009
#define KI_HIGH               ( 150)      // 0.015
//--------------------------------------------------------------------
//             TABLES
//--------------------------------------------------------------------

const struct SPIParameters T_S_PI_PARAMETERS[MAX_K_PARAMETERS]=
{
     {KP_EXTRA_HIGH, KI_HIGH},      //Index 0
     {KP_HIGH, KI_HIGH},            //Index 1
     {KP_MID, KI_HIGH},             //Index 2
     {KP_LOW, KI_HIGH},             //Index 3
     {KP_LOW, KI_MID},              //Index 4
     {KP_HIGH, KI_MID},             //Index 5
     {KI_MID, KI_MID},              //Index 6
     {KP_HIGH, KI_LOW},             //Index 7
};


void SR_InitRam(void)
{
    bMotor = OFF;
    capture_overflow = 0;
    u32CaptureCounter = 0;
    u64TimeCaptured = 0;

    u16SetpointValueold = 0;
    u16SetpointValue = 0;

    u8DutyCycleReal = 0;

    i32SpeedError2= 0;
    i32SpeedError1= 0;
    i32SpeedError0= 0;

    i64Proporcial= 0;
    i64Integral= 0;

    i64CalcPI= 0;

    i64Calculation= 0;
}
