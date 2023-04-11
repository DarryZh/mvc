#include <stdio.h>
#include <assert.h>
#include "event_manager.h"

static event_handle_t *__event_manager_context[EVENT_NUM_MAX][EVENT_HANDLE_NUM_MAX] = { 0 };

//static 
//event_handle_t ****__event_manager_context = NULL;

int event_manager_init(void) 
{
//#ifdef EVENT_MANAGER_USE__MALLOC
//	__event_manager_context = malloc(EVENT_MAX * TASK_MAX);
//	if (__event_manager_context == NULL) {
//		return -1;
//	}
//#else
//	static event_handle_t*  __event_manager_context_impl[EVENT_MAX][TASK_MAX] = { 0 };
//	__event_manager_context = &__event_manager_context_impl;
//#endif

	return 0;
}

static
int __append_event(unsigned char event, event_handle_t *handle)
{
	handle->event_cache_array[handle->write_offset] = event;
	if (handle->write_offset != EVENT_CACHE_ARRAY_SIZE - 1) {
		handle->write_offset++;
	}
	else {
		handle->write_offset = 0;
	}
	if (handle->write_offset == handle->read_offset) {
		printf("[%d] event cache array full!\n", __LINE__);
		assert(0);//full
	}
	return 0;
}

static
int __read_event(unsigned char *p_event, event_handle_t *handle)
{
	if (handle->read_offset == handle->write_offset) {
		return -1;
	}
	*p_event = handle->event_cache_array[handle->read_offset];
	if (handle->read_offset != EVENT_CACHE_ARRAY_SIZE - 1) {
		handle->read_offset++;
	}
	else {
		handle->read_offset = 0;
	}
	return 0;
}

int event_register(unsigned char event, event_handle_t* event_handle)
{
	for (int i = 0; i < EVENT_HANDLE_NUM_MAX; i++) {
		if (__event_manager_context[event][i] == 0) {
			__event_manager_context[event][i] = event_handle;
			return 0;
		}
	}

	assert(0);
	return -1;
}

int send_event_async(unsigned char event)
{
	int ret = 0,i = 0;
	while (i < EVENT_HANDLE_NUM_MAX)
	{
		event_handle_t* event_handle = __event_manager_context[event][i];
		if (event_handle != NULL) {
			ret = __append_event(event, event_handle);
			if (ret != 0) {

			}
		}
		i++;
	}
	
	return ret;
}

int try_receive_event_async(unsigned char *p_event, event_handle_t *handle)
{
	return __read_event(p_event, handle);
}
	