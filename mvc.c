#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "__view_impl.h"
#include "__controll_impl.h"

#undef this
#define this	(*ptThis)

static view_task_handle_t view_task_handle;

int mvc_raw_entry(mvc_task_handle_t *ptThis)
{
	view_sub_task(&view_task_handle);
	controll_sub_task(ptThis);

	return 0;
}
