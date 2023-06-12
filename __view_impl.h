#ifndef ____VIEW_IMPL_H__
#define ____VIEW_IMPL_H__

typedef struct {
	unsigned char chState;
} view_task_handle_t;

int view_sub_task(view_task_handle_t* ptThis);

#endif
