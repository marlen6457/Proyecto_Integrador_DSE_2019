#ifndef SYSTEM_API_H
#define SYSTEM_API_H

typedef enum
{

    /** Time data. */
    GXEVENT_MSG_UPDATE_TIME,
} gx_event_message_t;



typedef struct st_system_payload
{
 float system_var;
} system_payload_t;
#endif /* TEMPERATURE_API_H */
