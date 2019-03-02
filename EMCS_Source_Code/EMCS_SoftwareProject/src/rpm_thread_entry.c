#include "rpm_thread.h"
#include "Ram.h"

/* RPM Thread entry function */
void rpm_thread_entry(void)
{
//    /* Initialize Input Capture Driver */
//    g_input_capture.p_api->open(g_input_capture.p_ctrl,g_input_capture.p_cfg);
//    g_input_capture.p_api->enable(g_input_capture.p_ctrl);
//
//    /* TODO: add your own code here */
    while (1)
    {
        tx_thread_sleep (1);
    }
}

void SR_InputCapture_CallBack(input_capture_callback_args_t *p_args)
{
    static uint32_t pclk_freq_hz = 0;
//
//        switch(p_args->event)
//        {
//            case INPUT_CAPTURE_EVENT_MEASUREMENT:
//
//                /* Get the value of the captured counter and overflows number */
//                capture_counter = p_args->counter;
//
//                /* Get the frequency of PCLKD in Hz*/
//                g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKD, &pclk_freq_hz);
//
//                /* Calculate time value of measurement (ns)
//                 * Nanoseconds (ns) time_ns = ((overflows * max_counts) + counter) * 1000000000 / clk_freq_hz ***SELECTED**
//                   Microseconds (us) time_ns = ((overflows * max_counts) + counter) * 1000000 / clk_freq_hz
//                   Milliseconds (ms) time_ns = ((overflows * max_counts) + counter) * 1000 / clk_freq_hz
//                   Seconds (s) time_ns = ((overflows * max_counts) + counter) / clk_freq_hz
//                 * */
//                time_captured = (uint64_t)(((capture_overflow * BIT_32) + (uint64_t)capture_counter) * TIMER_NANOSECOND / pclk_freq_hz);
//
//                time_captured = 0;
//                capture_overflow = 0;
//                break;
//
//            case INPUT_CAPTURE_EVENT_OVERFLOW:
//
//                /* Overflows counter add one */
//                capture_overflow++;
//
//                break;
//            default:
//                break;
//        }
 }

