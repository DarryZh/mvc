#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "board_config.h"

#include "log.h"
#include "mvc.h"

#include "controll_templete.h"

#include "disp.h"
#include "input.h"
#include "input_event_def.h"
#include "widget_win.h"
#include "widget_clock.h"
#include "widget_bar.h"

obj_t *app_win, *oops_win;
obj_t *clock0, *clock1, *clock2, *clock3, *clock4;
obj_t *cooler_bar;
obj_t *cooler_icon;

enum {
    APP_WIN_CURSOR_INVAILD = 0,
};

///////////////////////////////////////////////////////////////////////////////////////////

static 
void app_input_2_user_request(unsigned int event)
{
    uint8_t cursor = get_disp_root()->cur_win->cursor;
    LOG_D("[view][app win] cursor %d", cursor);
	switch (event)
    {
    case INPUT_SET_LONG:

        break;
    case INPUT_SET:

        break;
    case INPUT_COOLER:

        break;
    case INPUT_COOLER_LONG:

        break;
    case INPUT_UP:

        break;
    case INPUT_DOWN:

        break;
    case INPUT_COMBINE_SET_UP_LONG:

        break;
    case INPUT_COMBINE_SET_DOWN_LONG:

        break;
    case INPUT_COMBINE_UP_DOWN_LONG:

        break;
    default:
        assert(0);
        break;
    }
}

static 
void oops_input_2_user_request(unsigned int event)
{
    uint8_t cursor = get_disp_root()->cur_win->cursor;
    LOG_D("[view][oops win] cursor %d", cursor);
	switch (event)
    {
    case INPUT_SET_LONG:

        break;
    case INPUT_SET:

        break;
    case INPUT_COOLER:

        break;
    case INPUT_COOLER_LONG:

        break;
    case INPUT_UP:

        break;
    case INPUT_DOWN:

        break;
    case INPUT_COMBINE_SET_UP_LONG:

        break;
    case INPUT_COMBINE_SET_DOWN_LONG:

        break;
    case INPUT_COMBINE_UP_DOWN_LONG:
        
        break;
    default:
        assert(0);
        break;
    }
}

void input_2_user_request(unsigned int event)
{
	LOG_D("[view][input event] %d", event);
    LOG_D("[app win] %08x", app_win);
    LOG_D("[oops win] %08x", oops_win);
    LOG_D("[disp win] %08x", get_disp_root()->cur_win);
    if(get_disp_root()->cur_win == app_win){
        app_input_2_user_request(event);
    } else if(get_disp_root()->cur_win == oops_win){
        oops_input_2_user_request(event);
    } else {
        assert(0);
    }
    
}
///////////////////////////////////////////////////////////////////////////////////////////

static
void app_win_init(obj_t * obj)
{
    LOG_D("[view] app_win_init");
    win_t * win = (win_t *)obj;

    cooler_bar = bar_create(obj);
	clock0 = clock_create(obj);
	clock_bingding(clock0, 0, 1, 2, 3, 0, 9, 11, 12);
	
	clock1 = clock_create(obj);
	clock_bingding(clock1, 4, 5, 6, 7, 1, 5, 13, 14);
	clock2 = clock_create(obj);
	clock_bingding(clock2, 8, 9, 10, 11, 2, 6, 15, 16);
	clock3 = clock_create(obj);
	clock_bingding(clock3, 12, 13, 14, 15, 3, 7, 17, 18);
	clock4 = clock_create(obj);
	clock_bingding(clock4, 16, 17, 18, 19, 4, 8, 19, 20);

	cooler_icon = icon_create(obj);
	icon_bingding(cooler_icon, 10);	

    clock_blink_set(clock0, WIDGET_CLOCK_ICON_BLINK_FLAG, 0);
    clock_blink_set(clock1, WIDGET_CLOCK_ICON_BLINK_FLAG, 0);
    clock_blink_set(clock2, WIDGET_CLOCK_ICON_BLINK_FLAG, 0);
    clock_blink_set(clock3, WIDGET_CLOCK_ICON_BLINK_FLAG, 0);
    clock_blink_set(clock4, WIDGET_CLOCK_ICON_BLINK_FLAG, 0);
    clock_blink_set(clock1, WIDGET_CLOCK_DOT_BLINK_FLAG, 0);
    clock_blink_set(clock2, WIDGET_CLOCK_DOT_BLINK_FLAG, 0);
    clock_blink_set(clock3, WIDGET_CLOCK_DOT_BLINK_FLAG, 0);
    clock_blink_set(clock4, WIDGET_CLOCK_DOT_BLINK_FLAG, 0);

    clock_blink_set(clock0, WIDGET_CLOCK_DOT_BLINK_FLAG, 1);
}
static
void app_win_exit(obj_t * obj)
{
    LOG_D("[view] app_win_exit");
    win_t * win = (win_t *)obj;

    clock_timer_destory(clock0);
    clock_timer_destory(clock1);
    clock_timer_destory(clock2);
    clock_timer_destory(clock3);
    clock_timer_destory(clock4);
}

static
void oops_win_init(obj_t * obj)
{
    LOG_D("[view] oops_win_init");
    win_t * win = (win_t *)obj;

}
static
void oops_win_exit(obj_t * obj)
{
    LOG_D("[view] oops_win_exit");
    win_t * win = (win_t *)obj;

}

void view_init(void) 
{
    LOG_D("[view] init");
	app_win = win_create(get_disp_root()->root);
	oops_win = win_create(get_disp_root()->root);

    win_enter(app_win, app_win_init, app_win_exit);

    v2c_ipc_write(USER_REQ_APP_WIN_ENTRY);
}

///////////////////////////////////////////////////////////////////////////////////////////

// model update 

int clock_data_model_update(clock_data_model_t *clock)
{
    clock_data_model_t clock_data = *clock;

    return 0;
}
int alarm1_data_model_update(alarm1_data_model_t *alarm1)
{
    alarm1_data_model_t alarm1_data = *alarm1;

    return 0;
}
int alarm2_data_model_update(alarm2_data_model_t *alarm2)
{
    alarm2_data_model_t alarm2_data = *alarm2;

    return 0;
}
int alarm3_data_model_update(alarm3_data_model_t *alarm3)
{
    alarm3_data_model_t alarm3_data = *alarm3;

    return 0;
}
int alarm4_data_model_update(alarm4_data_model_t *alarm4)
{
    alarm4_data_model_t alarm4_data = *alarm4;

    return 0;
}
int cooler_data_model_update(cooler_data_model_t *cooler)
{
    cooler_data_model_t cooler_data = *cooler;

    return 0;
}

void view_register_init(void)
{
	LOG_D("[view][register] clock");
	view_DataModel_register(clock, clock_data_model_update);
	LOG_D("[view][register] alarm1");
	view_DataModel_register(alarm1, alarm1_data_model_update);
	LOG_D("[view][register] alarm2");
	view_DataModel_register(alarm2, alarm2_data_model_update);
	LOG_D("[view][register] alarm3");
	view_DataModel_register(alarm3, alarm3_data_model_update);
	LOG_D("[view][register] alarm4");
	view_DataModel_register(alarm4, alarm4_data_model_update);
	LOG_D("[view][register] cooler");
	view_DataModel_register(cooler, cooler_data_model_update);

}

///////////////////////////////////////////////////////////////////////////////////////////
