/* generated messaging source file - do not edit */
#include "sf_message.h"
#ifndef SF_MESSAGE_CFG_QUEUE_SIZE
#define SF_MESSAGE_CFG_QUEUE_SIZE (16)
#endif
TX_QUEUE main_thread_message_queue;
static uint8_t queue_memory_main_thread_message_queue[SF_MESSAGE_CFG_QUEUE_SIZE];
static sf_message_subscriber_t main_thread_message_queue_0_0 =
{ .p_queue = &main_thread_message_queue, .instance_range =
{ .start = 0, .end = 0 } };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_TOUCH[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_TOUCH =
{ .event_class = SF_MESSAGE_EVENT_CLASS_TOUCH, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_TOUCH };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_SETPOINT[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_SETPOINT =
{ .event_class = SF_MESSAGE_EVENT_CLASS_SETPOINT, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_SETPOINT };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_DUTY[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_DUTY =
{ .event_class = SF_MESSAGE_EVENT_CLASS_DUTY, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_DUTY };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_RPMS[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_RPMS =
{ .event_class = SF_MESSAGE_EVENT_CLASS_RPMS, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_RPMS };
static sf_message_subscriber_t *gp_group_SF_MESSAGE_EVENT_CLASS_SYSTEM[] =
{ &main_thread_message_queue_0_0, };
static sf_message_subscriber_list_t g_list_SF_MESSAGE_EVENT_CLASS_SYSTEM =
{ .event_class = SF_MESSAGE_EVENT_CLASS_SYSTEM, .number_of_nodes = 1, .pp_subscriber_group =
          gp_group_SF_MESSAGE_EVENT_CLASS_SYSTEM };
sf_message_subscriber_list_t *p_subscriber_lists[] =
{ &g_list_SF_MESSAGE_EVENT_CLASS_TOUCH, &g_list_SF_MESSAGE_EVENT_CLASS_SETPOINT, &g_list_SF_MESSAGE_EVENT_CLASS_DUTY,
  &g_list_SF_MESSAGE_EVENT_CLASS_RPMS, &g_list_SF_MESSAGE_EVENT_CLASS_SYSTEM, NULL };
void g_message_init(void);
void g_message_init(void)
{
    tx_queue_create (&main_thread_message_queue, (CHAR *) "Main Thread Message Queue", 1,
                     &queue_memory_main_thread_message_queue, sizeof(queue_memory_main_thread_message_queue));
}
