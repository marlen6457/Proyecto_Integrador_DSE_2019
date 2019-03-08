/* generated thread header file - do not edit */
#ifndef RPM_THREAD_H_
#define RPM_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void rpm_thread_entry(void);
#else
extern void rpm_thread_entry(void);
#endif
#include "r_gpt_input_capture.h"
#include "r_input_capture_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** Timer on GPT Instance. */
extern const input_capture_instance_t g_input_capture;
#ifndef SR_InputCapture_CallBack
void SR_InputCapture_CallBack(input_capture_callback_args_t *p_args);
#endif
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* RPM_THREAD_H_ */
