#include "pwm_thread.h"
#include "Ram.h"
#include "sf_message_payloads.h"

/***********************************************************************
 Name:          SR_StartStopMotor
 Returns:       None
 Called by:     pwm_thread_entry()
 Calls:         None
 Description:   RUN and STOP the Motor control through Pin 203 output

***********************************************************************/
void SR_StartStopMotor(void)
{
    if(bMotor)
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_02_PIN_03, IOPORT_LEVEL_HIGH);
    }
    else
    {
        g_ioport.p_api->pinWrite(IOPORT_PORT_02_PIN_03, IOPORT_LEVEL_LOW);
    }
}

/***********************************************************************
 Name:          SR_ControlPI
 Returns:       None
 Called by:     FN_u8RampTime( )
                FN_u8RampUnfolding( )
                FN_u8RampJerk( )
                FN_u8StepTime( )
                FN_u8StepUnfolding( )
                FN_u8StepJerk( )
 Calls:         None
 Description:   PI Control- DC MOTOR

***********************************************************************/
void SR_ControlPI(uint32_t lu32TargetSpeed, uint8_t lu8Index )
{
    uint16_t lu16Kp;
    uint16_t lu16Ki;

    i32SpeedError2 = i32SpeedError1;
    i32SpeedError1 = i32SpeedError0;
    i32SpeedError0 = ((uint32_t) lu32TargetSpeed - (uint32_t) u16RPMvalueAvg)*(uint32_t) (CONST_SCALE);

    lu16Kp = T_S_PI_PARAMETERS[lu8Index].u16Kp;
    lu16Ki = T_S_PI_PARAMETERS[lu8Index].u16Ki;


    //i64Proporcial = (uint64_t)((uint64_t) lu16Kp * ((uint64_t) i32SpeedError0 - (uint64_t) i32SpeedError1));
    i64Proporcial = (uint64_t) (lu16Kp) * ((uint64_t) (i32SpeedError0)- (uint64_t) (i32SpeedError1));
    //i64Integral   = (uint64_t)((uint64_t) lu16Ki * (uint64_t) i32SpeedError0);

    i64CalcPI = (i64Proporcial + i64Integral);
    //i64CalcPI = i64Proporcial;

    i64CalcPI = i64CalcPI / (uint64_t) CONST_SCALE;

    i64Calculation = (uint64_t) u8DutyCycleReal +  (uint64_t) ( i64CalcPI);


    if ( i64Calculation >= 0)
      {
        if (i64Calculation < 10000 )
          {
            u8DutyCycleReal = (uint8_t) (i64Calculation);

          }
        else
          {
            u8DutyCycleReal = 100;

          }

      }
    else
      {
        u8DutyCycleReal = 0;
      }

}


/*****************************************************************************
 Name:          SR_Dutycycle_message
 InputParam:    None
 Called by:     pwm_thread_entry()
 Calls:         None
 Description:   Posts Dutycycle PWM signal message to messaging framework.

********************************************************************************/
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

/*****************************************************************************
 Name:          pwm_thread_entry
 InputParam:
 Called by:
 Calls:         SR_Dutycycle_message()
 Description:   PWM Thread entry function

********************************************************************************/
void pwm_thread_entry(void)
{
    // Open the timer 1 using the configured options from the configurator
     g_timer.p_api->open (g_timer.p_ctrl, g_timer.p_cfg);
     g_timer.p_api->start (g_timer.p_ctrl);
    /* TODO: add your own code here */
    while (1)
    {
        SR_StartStopMotor();
        SR_ControlPI(u16SetpointValue,2);
        u8DutyCycleInst = (uint8_t) ((100) - u8DutyCycleReal);
        SR_Dutycycle_message();
        g_timer.p_api->dutyCycleSet(g_timer.p_ctrl, u8DutyCycleInst, TIMER_PWM_UNIT_PERCENT, 0);
        tx_thread_sleep (1);
    }
}


