#include "adc_thread.h"
#include "Ram.h"
#include "sf_message_payloads.h"
#include <stdio.h>

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

        u16ADC_FilterdData = (uint16_t)(u16ADC_Data + ((uint16_t)(C_FILTER_ORDER) - 1) * u16ADC_FilterdData) / (uint16_t)(C_FILTER_ORDER);
        u16SetpointValue = ((uint16_t)(3200)*(u16ADC_FilterdData))/((uint16_t)(4095));
        snprintf(g_setpoint_value, sizeof(g_setpoint_value), "%d", u16SetpointValue);

        SR_SetpointADC_message();
//        if(u16ADC_Data > 512)
//        {
//            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
//        }
//        else
//        {
//            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
//        }

        tx_thread_sleep (10);
    }
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
