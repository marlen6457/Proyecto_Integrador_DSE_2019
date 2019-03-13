#include "pwm_thread.h"
#include "Ram.h"

/* PWM Thread entry function */
void pwm_thread_entry(void)
{
    // Open the timer 1 using the configured options from the configurator
     g_timer.p_api->open (g_timer.p_ctrl, g_timer.p_cfg);
     g_timer.p_api->start (g_timer.p_ctrl);
    /* TODO: add your own code here */
    while (1)
    {
        //u8DutyCycleReal = (uint8_t)(u16ADC_FilterdData * 100/4095);
        //u8DutyCycleReal = 100;
        u8DutyCycleInst = (uint8_t) (100) - u8DutyCycleReal;
        g_timer.p_api->dutyCycleSet(g_timer.p_ctrl, u8DutyCycleInst, TIMER_PWM_UNIT_PERCENT, 0);

        tx_thread_sleep (1);
    }
}
