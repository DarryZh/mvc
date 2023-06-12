#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "event_def.h"
#include "mvc.h"

#include "controll_templete.h"

void v2c_user_req_handle(unsigned int event)
{
    switch (event)
    {
    case USER_REQ_APP_WIN_ENTRY:

        break;
    case USER_REQ_OOPS_WIN_ENTRY:

        break;
    case USER_REQ_COOLER_ON_OFF:

        break;
    case USER_REQ_COOLER_SWITCH:

        break;
    case USER_REQ_SETTING:

        break;
    case USER_REQ_SAVE_CLOCK:
        {

        }
        break;
    case USER_REQ_SAVE_ALARM1:
        {

        }
        break;
    case USER_REQ_SAVE_ALARM2:
        {

        }
        break;
    case USER_REQ_SAVE_ALARM3:
        {

        }
        break;
    case USER_REQ_SAVE_ALARM4:
        {

        }
        break;
    case USER_REQ_CLR_ALARM1:
        {

        }
        break;
    case USER_REQ_CLR_ALARM2:
        {

        }
        break;
    case USER_REQ_CLR_ALARM3:
        {

        }
        break;
    case USER_REQ_CLR_ALARM4:
        {

        }
        break;
    case USER_REQ_CLR_STALL_OR_RUN_ONCE:

        break;
    
    default:
        assert(0);
        break;
    }
}

void extern_controll_event_handle(unsigned int event)
{
    switch (event)
    {
    case EVENT_ALARM_ACHIEVE:
        
        break;
    case EVENT_COOLER_MODE_1:

        break;
    case EVENT_COOLER_MODE_3:

        break;
    case EVENT_COOLER_DISABLE:

        break;
    case EVENT_COOLER_ENABLE:

        break;
    case EVENT_MOTOR_WORK_PREPARE:

        break;
    case EVENT_MOTOR_WORK_COMPLETE:

        break;
    case EVENT_MOTOR_TASK_RESET_AND_RUN_ONCE:

        break;
    case EVENT_CLOCK_MIN_UPDATE:
        {

        }
        break;
    case EVENT_ALARM_SORT_REFLESH:
        {

        }
        break;
    default:
        assert(0);
        break;
    }
}
