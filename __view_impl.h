#ifndef ____VIEW_IMPL_H__
#define ____VIEW_IMPL_H__

#include "event_manager.h"

typedef struct {
	unsigned char chState;
	event_handle_t event_handle;
} view_task_handle_t;

int view_task(view_task_handle_t* ptThis);

#endif
