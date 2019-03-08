/* generated thread source file - do not edit */
#include "rpm_thread.h"

TX_THREAD rpm_thread;
void rpm_thread_create(void);
static void rpm_thread_func(ULONG thread_input);
static uint8_t rpm_thread_stack[1024] BSP_PLACE_IN_SECTION_V2(".stack.rpm_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if !defined(SSP_SUPPRESS_ISR_g_input_capture) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_counter_overflow_isr, GPT, COUNTER_OVERFLOW, 0);
#endif
#if !defined(SSP_SUPPRESS_ISR_g_input_capture) && !defined(SSP_SUPPRESS_ISR_GPT0)
SSP_VECTOR_DEFINE_CHAN(gpt_input_capture_isr, GPT, CAPTURE_COMPARE_A, 0);
#endif
static gpt_input_capture_instance_ctrl_t g_input_capture_ctrl;
static const gpt_input_capture_extend_t g_input_capture_extend =
{ .signal = GPT_INPUT_CAPTURE_SIGNAL_PIN_GTIOCA, .signal_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, .clock_divider =
          GPT_INPUT_CAPTURE_CLOCK_DIVIDER_1,
  .enable_level = INPUT_CAPTURE_SIGNAL_LEVEL_NONE, .enable_filter = GPT_INPUT_CAPTURE_SIGNAL_FILTER_NONE, };
static const input_capture_cfg_t g_input_capture_cfg =
{ .channel = 0, .mode = INPUT_CAPTURE_MODE_PERIOD, .edge = INPUT_CAPTURE_SIGNAL_EDGE_RISING, .repetition =
          INPUT_CAPTURE_REPETITION_PERIODIC,
  .autostart = true, .p_callback = SR_InputCapture_CallBack, .p_context = &g_input_capture, .p_extend =
          &g_input_capture_extend,
  .capture_irq_ipl = (4), .overflow_irq_ipl = (4), };
/* Instance structure to use this module. */
const input_capture_instance_t g_input_capture =
{ .p_ctrl = &g_input_capture_ctrl, .p_cfg = &g_input_capture_cfg, .p_api = &g_input_capture_on_gpt };
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void rpm_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&rpm_thread, (CHAR *) "RPM Thread", rpm_thread_func, (ULONG) NULL, &rpm_thread_stack, 1024,
                            9, 9, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&rpm_thread, 0);
    }
}

static void rpm_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */

    /* Enter user code for this thread. */
    rpm_thread_entry ();
}
