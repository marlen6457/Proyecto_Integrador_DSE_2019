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
        U8DutyCycle = (uint8_t)(u16ADC_Data * 100/4095);
        g_timer.p_api->dutyCycleSet(g_timer.p_ctrl, U8DutyCycle, TIMER_PWM_UNIT_PERCENT, 0);

        tx_thread_sleep (1);
    }
}
