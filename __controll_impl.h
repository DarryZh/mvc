#ifndef ____CONTROLL_IMPL_H__
#define ____CONTROLL_IMPL_H__

#include <stdint.h>
//extern event config
#include "event_manager.h"

typedef struct
{
    unsigned char chState;
    event_handle_t event_handle;

} mvc_task_handle_t;

int controll_sub_task(mvc_task_handle_t *ptThis);

#endif
