/* generated messaging header file - do not edit */
#ifndef SF_MESSAGE_PAYLOADS_H_
#define SF_MESSAGE_PAYLOADS_H_
#include "sf_touch_panel_api.h"
#include "dutycycle_api.h"
#include "setpoint_api.h"
#include "rpmsignal_api.h"
typedef union u_sf_message_payload
{
    sf_touch_panel_payload_t sf_touch_panel_payload;
    dutycycle_payload_t dutycycle_payload;
    setpoint_payload_t setpoint_payload;
    rpmsignal_payload_t rpmsignal_payload;
} sf_message_payload_t;
#endif /* SF_MESSAGE_PAYLOADS_H_ */
