/* generated messaging header file - do not edit */
#ifndef SF_MESSAGE_PORT_H_
#define SF_MESSAGE_PORT_H_
typedef enum e_sf_message_event_class
{
    SF_MESSAGE_EVENT_CLASS_TOUCH, /* Touch */
    SF_MESSAGE_EVENT_CLASS_DUTYCYCLE, /* DutyCycle */
    SF_MESSAGE_EVENT_CLASS_SETPOINT, /* Setpoint */
    SF_MESSAGE_EVENT_CLASS_RPMSIGNAL, /* RPMsignal */
} sf_message_event_class_t;
typedef enum e_sf_message_event
{
    SF_MESSAGE_EVENT_UNUSED, /* Unused */
    SF_MESSAGE_EVENT_NEW_DATA, /* New Data */
    SF_MESSAGE_EVENT_UPDATE_DUTY_CYCLE, /* Update Duty Cycle */
    SF_MESSAGE_EVENT_SETPOINT_VALUE, /* Setpoint Value */
    SF_MESSAGE_EVENT_RPM_READ, /* RPM Read */
} sf_message_event_t;
extern TX_QUEUE main_thread_message_queue;
#endif /* SF_MESSAGE_PORT_H_ */
