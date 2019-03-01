#include "adc_thread.h"
#include "Ram.h"
//#include <stdio.h>

/* Control Thread entry function */
void adc_thread_entry(void)
{
    SR_InitRam();
    g_adc0.p_api->open (g_adc0.p_ctrl, g_adc0.p_cfg);
    g_adc0.p_api->scanCfg (g_adc0.p_ctrl, g_adc0.p_channel_cfg);
    g_adc0.p_api->scanStart (g_adc0.p_ctrl);

    while (1)
    {
        //********ADC & PWM ***************
        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &u16ADC_Data);

        u16ADC_FilterdData = (u16ADC_Data + (C_FILTER_ORDER-1) * u16ADC_FilterdData) / C_FILTER_ORDER;
        if(u16ADC_Data > 512)
        {
            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_HIGH);
        }
        else
        {
            g_ioport.p_api->pinWrite(IOPORT_PORT_06_PIN_00, IOPORT_LEVEL_LOW);
        }

        tx_thread_sleep (10);
    }
}