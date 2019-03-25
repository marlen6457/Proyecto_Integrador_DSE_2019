/***********************************************************************************************************************
 * Copyright [2015] Renesas Electronics Corporation and/or its licensors. All Rights Reserved.
 *
 * The contents of this file (the "contents") are proprietary and confidential to Renesas Electronics Corporation
 * and/or its licensors ("Renesas") and subject to statutory and contractual protections.
 *
 * Unless otherwise expressly agreed in writing between Renesas and you: 1) you may not use, copy, modify, distribute,
 * display, or perform the contents; 2) you may not use any name or mark of Renesas for advertising or publicity
 * purposes or in connection with your use of the contents; 3) RENESAS MAKES NO WARRANTY OR REPRESENTATIONS ABOUT THE
 * SUITABILITY OF THE CONTENTS FOR ANY PURPOSE; THE CONTENTS ARE PROVIDED "AS IS" WITHOUT ANY EXPRESS OR IMPLIED
 * WARRANTY, INCLUDING THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND
 * NON-INFRINGEMENT; AND 4) RENESAS SHALL NOT BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, OR CONSEQUENTIAL DAMAGES,
 * INCLUDING DAMAGES RESULTING FROM LOSS OF USE, DATA, OR PROJECTS, WHETHER IN AN ACTION OF CONTRACT OR TORT, ARISING
 * OUT OF OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THE CONTENTS. Third-party contents included in this file may
 * be subject to different terms.
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * File Name    : system_api.h
 * Description  : Header file for
 **********************************************************************************************************************/

/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *           06.03.2015 1.00    Initial Release.
 **********************************************************************************************************************/

#ifndef SYSTEM_API_H
#define SYSTEM_API_H

#include "gx_api.h"


/***********************************************************************************************************************
 * Macro definitions
 **********************************************************************************************************************/

/***********************************************************************************************************************
 * Typedef definitions
 **********************************************************************************************************************/

/** Conversion of system events to GUIX events */
typedef enum
{
    /** Some classes do not use the event enumeration. */
    GXEVENT_MSG_UNUSED = GX_FIRST_APP_EVENT,

    /** System data refresh. */
    GXEVENT_MSG_UPDATE_DUTY_CYCLE,
    GXEVENT_MSG_UPDATE_SETPOINT_VALUE,
    GXEVENT_MSG_UPDATE_RPM_READ,

//    /** Temperature set point adjustment. */
//    GXEVENT_MSG_TEMPERATURE_INCREMENT,
//    GXEVENT_MSG_TEMPERATURE_DECREMENT,
//
//    /** Time setting. */
//    GXEVENT_MSG_HOUR_MODE_TOGGLE,
//    GXEVENT_MSG_AM_PM_TOGGLE,
//    GXEVENT_MSG_TIME_UPDATE,
//    GXEVENT_MSG_DATE_UPDATE,
//
//    /** System settings. */
//    GXEVENT_MSG_FAN_TOGGLE,
//    GXEVENT_MSG_SYSTEM_MODE_TOGGLE,
//
//    /** Temperature unit settings. */
//    GXEVENT_MSG_TEMPERATURE_UNIT_C,
//    GXEVENT_MSG_TEMPERATURE_UNIT_F,
//
//    /** Display Settings. */
//    GXEVENT_MSG_BRIGHTNESS_INCREMENT,
//    GXEVENT_MSG_BRIGHTNESS_DECREMENT,
//
//    /** Volume Settings. */
//    GXEVENT_MSG_VOLUME_INCREMENT,
//    GXEVENT_MSG_VOLUME_DECREMENT,
//
//    /** Temperature data. */
//    GXEVENT_MSG_UPDATE_TEMPERATURE,
//
//    /** Time data. */
//    GXEVENT_MSG_UPDATE_TIME,
} gx_event_message_t;

typedef struct st_system_state
{
    int          dutycycle_t;
    uint16_t     setpoint_t;
    uint16_t     rpmsignal_t;

} system_state_t;

typedef struct st_system_payload
{
    GX_EVENT        gx_event;
} system_payload_t;

#endif /* SYSTEM_API_H */
