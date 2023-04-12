#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "__view_impl.h"

static view_task_handle_t view_task_handle;

int mvc_raw_entry(void)
{
	view_task(&view_task_handle);

	return 0;
}