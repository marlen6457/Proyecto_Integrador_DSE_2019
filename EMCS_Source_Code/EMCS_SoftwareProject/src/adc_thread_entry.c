#include "adc_thread.h"
#include "Ram.h"
#include "sf_message_payloads.h"


/* Control Thread entry function */
void adc_thread_entry(void)
{
    SR_InitRam();
    g_adc0.p_api->open (g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg (g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart (g_adc0.p_ctrl);

    while (1)
    {
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &u16ADC_Data);     //Reading ADC pin - Potentiometer
        u16ADC_FilterdData = (uint16_t)(u16ADC_Data + ((uint16_t)(FILTER_ORDER) - 1) * u16ADC_FilterdData) / (uint16_t)(FILTER_ORDER);
        //u16SetpointValue = (uint16_t)(((uint16_t)(3200)*(u16ADC_FilterdData))/((uint16_t)(4095)));
        u16SetpointValue = FN_GetSetpoitValue(u16ADC_FilterdData);
        if(u16SetpointValue != u16SetpointValueold)
        {
            SR_SetpointADC_message();
            u16SetpointValueold = u16SetpointValue;
        }

        tx_thread_sleep (10);
    }
}

/*****************************************************************************
Name:          FN_GetSetpoitValue
InputParam :    lu16ADCRaw
Called by:
Calls:         none
Description:   Get the Setpoint desired by user

******************************************************************************/
uint16_t FN_GetSetpoitValue (uint16_t lu16ADCRaw)
{
    uint16_t lu16Setpointvalue = 1;
    uint8_t lu8Counter = 0;
    uint16_t lu16ADCLvL = 0;

    do{
          lu16ADCLvL = (uint16_t)(lu16ADCLvL + STEP_ADC_DESIRED);                                                                    // Increment Table Index
          lu8Counter = (uint8_t)(lu8Counter + 1);
        }
        while(lu16ADCRaw > lu16ADCLvL);

    lu16Setpointvalue = (uint16_t)(STEP_SETPOINT_DESIRED*lu8Counter);

    return lu16Setpointvalue;
}
/*******************************************************************************************************************//**
 * @brief   Posts RPM signal message to messaging framework.
***********************************************************************************************************************/
void SR_SetpointADC_message(void)
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
    p_message->event_b.class_code = SF_MESSAGE_EVENT_CLASS_SETPOINT;
    p_message->event_b.code  = SF_MESSAGE_EVENT_SETPOINT_VALUE;
    p_payload = (sf_message_payload_t*)(p_message+1);
    p_payload->rpmsignal_payload.rpmsignal= (uint16_t)u16SetpointValue;

    /** Post message. */
    sf_message_post_err_t post_err;
    err = g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) p_message, &g_post_cfg, &post_err, TX_NO_WAIT);
    }
}
