

#include "gui/guiapp_resources.h"
#include "gui/guiapp_specifications.h"

#include "main_thread.h"

//static bool button_enabled = false;
int contador=0;
int contador2=0;
int contador3=0;
int adc_value=984;
int hundreds,tens,units=0;
int counter_aux=0;
int storage_var=0;
unsigned int   error_counter = 0;
int caso=0;

#define TIME_EVENT_TIMER     (100)

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



    }

    switch(contador)
    {
        case 1:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY1);
            break;
        case 2:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY2);
            break;

        case 3:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY3);
            break;

        case 4:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY4);
            break;

        case 5:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY5);
            break;

        case 6:
            update_text_id(widget->gx_widget_parent, ID_DAY, GX_STRING_ID_DAY6);
            break;

        case 7:
            update_text_id(widget->gx_widget_parent, ID_DAY, (GX_STRING_ID_DAY7));
            break;
    }

    switch(contador2)
    {
        case 1:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON1);
            break;

        case 2:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON2);
            break;

        case 3:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON3);
            break;

        case 4:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON4);
            break;

        case 5:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON5);
            break;

        case 6:
            update_text_id(widget->gx_widget_parent, ID_MONTH, GX_STRING_ID_MON6);
            break;

        case 7:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON7));
            break;

        case 8:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON8));
            break;

        case 9:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON9));
            break;

        case 10:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON10));
            break;

        case 11:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON11));
            break;

        case 12:
            update_text_id(widget->gx_widget_parent, ID_MONTH, (GX_STRING_ID_MON12));
            break;

    }

    switch(contador3)
    {
        case 1:
            update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR1);
            break;

        case 2:
            update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR2);
            break;

        case 3:
            update_text_id(widget->gx_widget_parent, ID_YEAR, GX_STRING_ID_YEAR3);
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









//------------------------
                case GX_SIGNAL(ID_REFRESH, GX_EVENT_CLICKED):
                               // contador=contador+1;
                                //if(contador==1){
                                  //      update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_ONE);

                                            //  }
                               // if(contador==2){
                                 //        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_TWO);

                                   //                                           }
                                //if(contador>=8){
                                  //                                  contador=0;
                                    //                            }

                            //    break;
//---------------------------------------------
                                tens=(adc_value%100)/10;

                                    switch(tens)
                                    {
                                     case 0:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_ZERO);
                                         break;

                                     case 1:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_ONE);
                                         break;

                                     case 2:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_TWO);
                                         break;

                                     case 3:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_THREE);
                                         break;

                                     case 4:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_FOUR);
                                         break;

                                     case 5:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_FIVE);
                                         break;

                                     case 6:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_SIX);
                                         break;

                                     case 7:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_SEVEN);
                                         break;

                                     case 8:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_EIGHT);
                                         break;

                                     case 9:
                                         update_text_id(widget->gx_widget_parent, ID_DEC, GX_STRING_ID_NINE);
                                         break;

                                     }


                                hundreds=adc_value/100;




                                switch(hundreds)
                                {
                                    case 0:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_ZERO);
                                        break;
                                    case 1:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_ONE);
                                        break;

                                    case 2:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_TWO);
                                        break;

                                    case 3:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_THREE);
                                        break;

                                    case 4:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_FOUR);
                                        break;
                                    case 5:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_FIVE);
                                        break;

                                    case 6:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_SIX);
                                        break;

                                    case 7:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_SEVEN);
                                        break;

                                    case 8:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_EIGHT);
                                        break;

                                    case 9:
                                        update_text_id(widget->gx_widget_parent, ID_RES, GX_STRING_ID_NINE);
                                        break;

                                }

                                units=adc_value%10;


                                switch(units)
                                {
                                    case 0:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_ZERO);
                                        break;
                                    case 1:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_ONE);
                                        break;

                                    case 2:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_TWO);
                                        break;

                                    case 3:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_THREE);
                                        break;

                                    case 4:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_FOUR);
                                        break;
                                    case 5:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_FIVE);
                                        break;

                                    case 6:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_SIX);
                                        break;

                                    case 7:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_SEVEN);
                                        break;

                                    case 8:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_EIGHT);
                                        break;

                                    case 9:
                                        update_text_id(widget->gx_widget_parent, ID_UNITS, GX_STRING_ID_NINE);
                                        break;

                                }


                                break;





//-----------------------------------------------------------------------

//-----------------------------
        default:
            result = gx_window_event_process(widget, event_ptr);
            break;
    }


    return result;
}



UINT window4_handler(GX_WINDOW *widget, GX_EVENT *event_ptr)
{
    UINT result = gx_window_event_process(widget, event_ptr);
    UINT status;
    GX_MULTI_LINE_TEXT_VIEW * my_text_view = &window4.window4_text_view;

    switch (event_ptr->gx_event_type){

        case GX_SIGNAL(ID_BACK_W4, GX_EVENT_CLICKED):
                show_window((GX_WINDOW*)&window2, (GX_WIDGET*)widget, true);
                break;




            if(caso==0)
            {
                case GX_EVENT_SHOW:
                    gx_system_timer_start(widget, TIME_EVENT_TIMER, 100, 0);
                    caso=caso+1;
                    return gx_window_event_process(widget, event_ptr);

            }

            if(caso==1)
            {
                    case GX_EVENT_TIMER:
                    caso=0;
                    status = gx_multi_line_text_view_text_set(my_text_view, "Evento_B");


                    if (GX_SUCCESS != status)
                    {
                        error_counter++;
                    }

            }



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












