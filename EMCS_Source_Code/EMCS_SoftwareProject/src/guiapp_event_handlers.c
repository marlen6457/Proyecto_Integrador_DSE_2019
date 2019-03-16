

#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"
#include "Ram.h"
#include <stdio.h>

#include "main_thread.h"

GX_WINDOW_ROOT * p_window_root;

GX_WINDOW*      p_splash_screen;
GX_WINDOW*      p_mainpage_screen;
GX_WINDOW*      p_credits_screen;
GX_WINDOW_ROOT* p_root;

extern GX_WINDOW_ROOT * p_window_root;

static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old);
static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id);
static void update_text(GX_WIDGET * p_widget, GX_RESOURCE_ID id, char * p_text);
static void update_pixelmap_button_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT button);
UINT settings_item_show(GX_WINDOW *widget, USHORT new_content, USHORT old_content);

static char g_dutycycle_value[5]    = "0000%";
static char g_setpoint_value[8]     = "0000rpm";
static char g_rpm_value[8]          = "0000rpm";



UINT splash_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type)
    {

        case GX_SIGNAL(ID_ICON_MORE, GX_EVENT_CLICKED):
        show_window((GX_WINDOW*)&main_page, (GX_WIDGET*)widget, true);
        break;

        case GX_SIGNAL(ID_ICON_TEAM, GX_EVENT_CLICKED):
        show_window((GX_WINDOW*)&credits_page, (GX_WIDGET*)widget, true);
        break;


    default:
        gx_window_event_process(widget, event_ptr);
        break;
    }

    return result;
}

UINT Mainpage_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);
    GX_WIDGET * p_widget = (GX_WIDGET *) widget;

    switch (event_ptr->gx_event_type)
    {

        case GX_SIGNAL(ID_BACK_BTN, GX_EVENT_CLICKED):
                 show_window((GX_WINDOW*)&splash_page, (GX_WIDGET*)widget, true);
                break;

        case GX_SIGNAL(ID_BTN_ON, GX_EVENT_CLICKED):
                update_pixelmap_button_id((GX_WIDGET *) p_widget, ID_FAN_STATUS, GX_PIXELMAP_ID_GREEN_STATUS);
                update_pixelmap_button_id((GX_WIDGET *) p_widget, ID_FAN_STATUS_OFF, GX_PIXELMAP_ID_GRAY_STATUS);
                update_text_id(widget->gx_widget_parent, ID_FAN_TEXT2, GX_STRING_ID_STATUS_OFF);
                update_text_id(widget->gx_widget_parent, ID_FAN_TEXT, GX_STRING_ID_STATUS_ON);
                break;

        case GX_SIGNAL(ID_BTN_OFF, GX_EVENT_CLICKED):
                update_pixelmap_button_id((GX_WIDGET *) p_widget, ID_FAN_STATUS_OFF, GX_PIXELMAP_ID_RED_STATUS);
                update_pixelmap_button_id((GX_WIDGET *) p_widget, ID_FAN_STATUS, GX_PIXELMAP_ID_GRAY_STATUS);
                update_text_id(widget->gx_widget_parent, ID_FAN_TEXT2, GX_STRING_ID_STATUS_OFF);
                update_text_id(widget->gx_widget_parent, ID_FAN_TEXT, GX_STRING_ID_STATUS_ON);
                break;

        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }
<<<<<<< HEAD
    snprintf(g_dutycycle_value, sizeof(g_dutycycle_value), "%d", u8DutyCycleReal);
=======
    update_text_id(widget->gx_widget_parent, ID_FAN_TEXT2, GX_STRING_ID_STATUS_OFF);
    update_text_id(widget->gx_widget_parent, ID_FAN_TEXT, GX_STRING_ID_STATUS_ON);
>>>>>>> Dex_fix_buttons
    update_text(widget->gx_widget_parent, ID_TEXT_DUTYCYCLE, g_dutycycle_value);
    snprintf(g_rpm_value, sizeof(g_rpm_value), "%d", u16RPMvalueAvg);
    update_text(widget->gx_widget_parent, ID_TEXT_RPM, g_rpm_value);
    snprintf(g_setpoint_value, sizeof(g_setpoint_value), "%d", u16SetpointValue);
    update_text(widget->gx_widget_parent, ID_TEXT_SETPOINT, g_setpoint_value);


    return result;
}

UINT Credits_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_CREDITS, GX_EVENT_CLICKED):
        show_window((GX_WINDOW*)&splash_page, (GX_WIDGET*)widget, true);
        break;

        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}



static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old)
{
    UINT err = GX_SUCCESS;

    if (!p_new->gx_widget_parent)
    {
        err = gx_widget_attach(p_window_root, p_new);
    }
    else
    {
        err = gx_widget_show(p_new);
    }

    gx_system_focus_claim(p_new);

    GX_WIDGET * p_old = p_widget;
    if (p_old && detach_old)
    {
        if (p_old != (GX_WIDGET*)p_new)
        {
            gx_widget_detach(p_old);
        }
    }

    return err;
}
/*******************************************************************************************************************//**
 * @brief   Helper function to update strings based on resource ID.
 *
 * @param[in]   p_widget    Parent widget (typically the current screen)
 * @param[in]   id          Resource ID of the widget to show or hide
 * @param[in]   p_text      Pointer to string to display
***********************************************************************************************************************/
static void update_text(GX_WIDGET * p_widget, GX_RESOURCE_ID id, char * p_text)
{
    GX_PROMPT * p_prompt = NULL;

    UINT err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET **) &p_prompt);
    if (GX_SUCCESS == err)
    {
        err = gx_prompt_text_set(p_prompt, p_text);
        if (GX_SUCCESS != err)
        {
            while(1);
        }

    }
}
/*******************************************************************************************************************//**
 * @brief   Helper function to update strings based on ID.
 *
 * @param[in]   p_widget    Parent widget (typically the current screen)
 * @param[in]   id          Resource ID of the widget to show or hide
 * @param[in]   string_id   ID of string to display
***********************************************************************************************************************/
static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id)
{
    GX_PROMPT * p_prompt = NULL;

    ssp_err_t err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_prompt_text_id_set(p_prompt, string_id);
    }
}
/*******************************************************************************************************************//**
 * @brief   Helper function to update pixelmap buttons based on ID.
 *
 * @param[in]   p_widget    Parent widget (typically the current screen)
 * @param[in]   id          Resource ID of the widget to show or hide
 * @param[in]   button      ID of button to display
***********************************************************************************************************************/
static void update_pixelmap_button_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT button)
{
    GX_PIXELMAP_BUTTON * p_button = NULL;

    UINT err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET **) &p_button);
    if (GX_SUCCESS == err)
    {
        err = gx_pixelmap_button_pixelmap_set(p_button, button, button, button);
        if (GX_SUCCESS != err) {
            while(1);
        }

    } else {
        while(1);
    }
}










