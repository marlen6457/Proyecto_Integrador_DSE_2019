

#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"

#include "main_thread.h"

//static bool button_enabled = false;
int contador=0;
int contador2=0;
int contador3=0;



extern GX_WINDOW_ROOT * p_window_root;

static UINT show_window(GX_WINDOW * p_new, GX_WIDGET * p_widget, bool detach_old);
static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id);

UINT window1_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type)
    {

        case GX_SIGNAL(ID_ICON_MORE, GX_EVENT_CLICKED):
        show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
        break;


    default:
        gx_window_event_process(widget, event_ptr);
        break;
    }

    return result;
}

UINT window2_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_BTN, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window1, (GX_WIDGET*)widget, true);
                break;

        case GX_SIGNAL(ID_BTN_DUTY, GX_EVENT_CLICKED):
                        show_window((GX_WINDOW*)&window3, (GX_WIDGET*)widget, true);
                        break;

        case GX_SIGNAL(ID_BTN_SPD, GX_EVENT_CLICKED):
                                show_window((GX_WINDOW*)&window4, (GX_WIDGET*)widget, true);
                                break;

        case GX_SIGNAL(ID_BTN_CTS, GX_EVENT_CLICKED):
                                        show_window((GX_WINDOW*)&window5, (GX_WIDGET*)widget, true);
                                        break;

        case GX_SIGNAL(ID_BTN_CAL, GX_EVENT_CLICKED):
                                                show_window((GX_WINDOW*)&window6, (GX_WIDGET*)widget, true);
                                                break;



        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}

UINT window3_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_W3, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
                break;

       // case GX_SIGNAL(ID_ADD, GX_EVENT_CLICKED):
         //       contador=contador+1;
           //     if(contador==1){
             //           update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_ONE);

               //               }
                //if(contador==2){
                  //      update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_TWO);

                    //       }
                //break;

        //case GX_SIGNAL(ID_MIN, GX_EVENT_CLICKED):
          //                      contador=contador-1;
            //                      update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_ONE);


              //         break;






        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}

UINT window4_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_W4, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
                break;


        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}


UINT window5_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_W5, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
                break;


        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}

UINT window6_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_W6, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
                break;
//------------------------
                case GX_SIGNAL(ID_UP_DAY, GX_EVENT_CLICKED):
                                contador=contador+1;
                                if(contador==1){
                                        update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY1);

                                              }
                                if(contador==2){
                                        update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY2);

                                           }
                                if(contador==3){
                                           update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY3);
                                                                                                           }

                                if(contador==4){
                                         update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY4);
                                }

                                if(contador==5){
                                         update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY5);
                                }
                                if(contador==6){
                                                                         update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY6);

                                }
                                if(contador==7){
                                        update_text_id(widget->gx_widget_parent, ID_DAY, (GX_STRING_ID_DAY7));
                                }
                                if(contador>=8){
                                                                    contador=0;
                                                                }

                                break;
//---------------------------------------------
                case GX_SIGNAL(ID_UP_MONTH, GX_EVENT_CLICKED):
                                                contador2=contador2+1;
                                                if(contador2==1){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON1);

                                                              }
                                                if(contador2==2){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON2);

                                                           }
                                                if(contador2==3){
                                                           update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON3);
                                                                                                                           }

                                                if(contador2==4){
                                                         update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON4);
                                                }

                                                if(contador2==5){
                                                         update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON5);
                                                }
                                                if(contador2==6){
                                                          update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON6);

                                                }
                                                if(contador2==7){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON7));
                                                }
                                               if(contador2==8){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON8));
                                                }

                                    if(contador2==9){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON9));
                                                }


                                    if(contador2==10){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON10));
                                                }

                                    if(contador2==11){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON11));
                                                }

                                    if(contador2==12){
                                                        update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON12));
                                                }



                                    if(contador2>=13){
                                                                                    contador2=0;
                                                             }

                                                break;


//-----------------------------------------------------------------------

                case GX_SIGNAL(ID_UP_YEAR, GX_EVENT_CLICKED):
                                                contador3=contador3+1;
                                                if(contador3==1){
                                                        update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR1);

                                                              }
                                                if(contador3==2){
                                                        update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR2);

                                                           }
                                                if(contador3==3){
                                                           update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR3);
                                                                                                                           }




                                    if(contador3>=4){
                                                                                    contador3=0;
                                                             }

                                                break;




//-----------------------------
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

static void update_text_id(GX_WIDGET * p_widget, GX_RESOURCE_ID id, UINT string_id)
{
    GX_PROMPT * p_prompt = NULL;

    ssp_err_t err = gx_widget_find(p_widget, (USHORT)id, GX_SEARCH_DEPTH_INFINITE, (GX_WIDGET**)&p_prompt);
    if (TX_SUCCESS == err)
    {
        gx_prompt_text_id_set(p_prompt, string_id);
    }
}

