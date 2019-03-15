#include "rpm_thread.h"
#include "Ram.h"
#include "sf_message_payloads.h"
#include <stdio.h>

/*****************************************************************************
 Name:          rpm_thread_entry
 InputParam:
 Called by:     SR_ProcessSensor( )
 Calls:         None
 Description:   RPM Thread entry function

********************************************************************************/
void rpm_thread_entry(void)
{

    g_input_capture.p_api->open(g_input_capture.p_ctrl,g_input_capture.p_cfg);          // Initialize Input Capture Driver.
    g_input_capture.p_api->enable(g_input_capture.p_ctrl);                              // Enables input capture measurement.
    tx_thread_sleep (10);
    SR_InitFilter (u16SpeedInst);
    while (1)
    {
        snprintf(g_rpm_value, sizeof(g_rpm_value), "%d", u16RPMvalueAvg);
        SR_RPMSignal_message();
        tx_thread_sleep (1);
    }
}

/*****************************************************************************
Name:          SR_InitFilter
InputParam :    li16InputData
Called by:
Calls:         none
Description:   Initializes the filter parameters

******************************************************************************/
void SR_InitFilter(uint16_t lu16InputData)
{
    u16InputValue        = lu16InputData;
    u32VarAccumulator    = (uint32_t) (lu16InputData * 0x80);            // Scale the RPM value by 128 and save to internal filter  average}
    u16InputValue        = lu16InputData;
}

/*****************************************************************************
 Name:          SR_FilterRPM
 InputParam:    uint32_t* lpi16Data      -> Instantaneous Data Address
                uint32_t* lpi32ShiftAdd  -> Sum of Previous data and Instantaneous Data Address
                int16_t* lpi16Result     -> Filter Result Address
 Called by:
 Calls:         None
 Description:   Filters a signed 16 bit variable using a 31:1 ratio from the current
                average vs the new sample value.
                Used to filter the temperature

********************************************************************************/
void SR_FilterRPM(uint16_t* lpu16Data, uint32_t* lpu32ShiftAdd, uint16_t* lpu16Result)
{
    uint32_t lu32InstantData;
    uint32_t lu32Temporal;

    lu32InstantData = ((uint32_t)(*lpu16Data) * 0x80);                           // Scale Instantaneous data by 128
    lu32Temporal    = lu32InstantData + (511 * (*lpu32ShiftAdd));                // Add Weighted Scaled Instantaneous data with Weighted Scaled Average Data
    *lpu32ShiftAdd  = (lu32Temporal / 512);                                      // Get new Scaled Average data
    *lpu16Result    = (uint16_t)( *lpu32ShiftAdd / 0x80 );                       // UnScale Average Data
}

/*****************************************************************************
 Name:          SR_InputCapture_CallBack
 InputParam:    input_capture_callback_args_t *p_args
 Called by:     none
 Calls:         None
 Description:   Callback to get capture time counter each rising signal edge
                Calculate time value of measurement (ns)
                   Nanoseconds  (ns) time_ns = ((overflows * max_counts) + counter) * 1000000000 / clk_freq_hz
                  *Microseconds (us) time_ns = ((overflows * max_counts) + counter) * 1000000 / clk_freq_hz **SELECTED**
                   Milliseconds (ms) time_ns = ((overflows * max_counts) + counter) * 1000 / clk_freq_hz
                   Seconds (s) time_ns = ((overflows * max_counts) + counter) / clk_freq_hz

********************************************************************************/
void SR_InputCapture_CallBack(input_capture_callback_args_t *p_args)
{
    static uint32_t pclk_freq_hz = 0;

        switch(p_args->event)
        {
            case INPUT_CAPTURE_EVENT_MEASUREMENT:

                u32CaptureCounter = p_args->counter;                                              // Get the value of the captured counter and overflows number

                g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclk_freq_hz);        //Get the frequency of PCLKD in Hz

                u64TimeCaptured = (uint64_t)(((capture_overflow * BIT_32) + (uint64_t)u32CaptureCounter) * TIMER_SECOND / (pclk_freq_hz));

                //u64TimeCaptured_ns = (uint32_t)((float)u64TimeCaptured + 0.5F);
                u32TimeCaptured_us = (uint32_t)(((float)u64TimeCaptured / (float)TIMER_MICROSECOND) + 0.5F);

                u32SpeedInst = ((MICRO_SECONDS_IN_A_MINUTE)/ (u32TimeCaptured_us)) * (uint32_t) (SCALED_FACTOR);

                u16SpeedInst = (uint16_t)((uint32_t)(u32SpeedInst)/(uint32_t)(MAGNET_POLES * SCALED_FACTOR));
                u16InputValue = u16SpeedInst;
                SR_FilterRPM (&u16InputValue, &u32VarAccumulator, &u16RPMvalueAvg);

                u64TimeCaptured = 0;                          // RESET Time Captured
                capture_overflow = 0;                       // RESET Overflow counter
                break;

            case INPUT_CAPTURE_EVENT_OVERFLOW:
                capture_overflow++;                         /* Overflows counter add one */

                break;
            default:
                break;
        }
 }
/*******************************************************************************************************************//**
 * @brief   Posts RPM signal message to messaging framework.
***********************************************************************************************************************/
void SR_RPMSignal_message(void)
{
    sf_message_header_t * p_message  = NULL;
    sf_message_payload_t * p_payload = NULL;
    /** Get buffer from messaging framework. */
    ssp_err_t err;
    err = g_sf_message0.p_api->bufferAcquire(g_sf_message0.p_ctrl, (sf_message_header_t **) &p_message, &g_acquire_cfg, TX_NO_WAIT);
    if (SSP_SUCCESS != err)
    {
        /** TODO_THERMO: Send error message. */
        while(1);
    }
    else
    {

    /** Create message in buffer. */
    p_message->event_b.class_code = SF_MESSAGE_EVENT_CLASS_RPMSIGNAL;
    p_message->event_b.code  = SF_MESSAGE_EVENT_RPM_READ;
    p_payload = (sf_message_payload_t*)(p_message+1);
    p_payload->rpmsignal_payload.rpmsignal= (uint16_t)u16RPMvalueAvg;

    /** Post message. */
    sf_message_post_err_t post_err;
    err = g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) p_message, &g_post_cfg, &post_err, TX_NO_WAIT);
    }
}

