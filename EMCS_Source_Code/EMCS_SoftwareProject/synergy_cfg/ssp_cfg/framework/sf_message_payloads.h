/* generated messaging header file - do not edit */
#ifndef SF_MESSAGE_PAYLOADS_H_
#define SF_MESSAGE_PAYLOADS_H_
#include "sf_touch_panel_api.h"
#include "setpoint_api.h"
#include "duty_api.h"
#include "rpms_api.h"
typedef union u_sf_message_payload
{
    sf_touch_panel_payload_t sf_touch_panel_payload;
    setpoint_payload_t setpoint_payload;
    duty_payload_t duty_payload;
    rpms_payload_t rpms_payload;
} sf_message_payload_t;
#endif /* SF_MESSAGE_PAYLOADS_H_ */
