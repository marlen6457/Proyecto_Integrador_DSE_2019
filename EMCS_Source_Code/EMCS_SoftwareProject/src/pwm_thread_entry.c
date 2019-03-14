#include "pwm_thread.h"
#include "Ram.h"
#include "sf_message_payloads.h"
#include <stdio.h>

/* PWM Thread entry function */
void pwm_thread_entry(void)
{
    // Open the timer 1 using the configured options from the configurator
     g_timer.p_api->open (g_timer.p_ctrl, g_timer.p_cfg);
     g_timer.p_api->start (g_timer.p_ctrl);
    /* TODO: add your own code here */
    while (1)
    {
        u8DutyCycleReal = (uint8_t)(u16ADC_FilterdData * 100/4095);
        //u8DutyCycleReal = 100;
        u8DutyCycleInst = (uint8_t) (100) - u8DutyCycleReal;
        snprintf(g_dutycycle_value, sizeof(g_dutycycle_value), "%d", u8DutyCycleReal);
        SR_Dutycycle_message();
        g_timer.p_api->dutyCycleSet(g_timer.p_ctrl, u8DutyCycleInst, TIMER_PWM_UNIT_PERCENT, 0);
        tx_thread_sleep (1);
    }
}
/*******************************************************************************************************************//**
 * @brief   Posts Dutycycle PWM signal message to messaging framework.
***********************************************************************************************************************/
void SR_Dutycycle_message(void)
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
    p_message->event_b.class_code = SF_MESSAGE_EVENT_CLASS_DUTYCYCLE;
    p_message->event_b.code  = SF_MESSAGE_EVENT_UPDATE_DUTY_CYCLE;
    p_payload = (sf_message_payload_t*)(p_message+1);
    p_payload->dutycycle_payload.dutycycle= (uint8_t)u8DutyCycleReal;

    /** Post message. */
    sf_message_post_err_t post_err;
    err = g_sf_message0.p_api->post(g_sf_message0.p_ctrl, (sf_message_header_t *) p_message, &g_post_cfg, &post_err, TX_NO_WAIT);
    }
}
