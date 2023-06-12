#include <stdio.h>
#include <assert.h>
#include "v2c_ipc.h"

typedef struct {
	unsigned char __ipc_ringbuff[V2C_IPC_RINGBUFF_SIZE];
	unsigned char read_offset;
	unsigned char write_offset;
} v2c_ipc_handle_t;

static v2c_ipc_handle_t __v2c_ipc_handle = { 0 };

int v2c_ipc_init(void) 
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
int __append_event(unsigned char event)
{
	__v2c_ipc_handle.__ipc_ringbuff[__v2c_ipc_handle.write_offset] = event;
	if (__v2c_ipc_handle.write_offset != V2C_IPC_RINGBUFF_SIZE - 1) {
		__v2c_ipc_handle.write_offset++;
	}
	else {
		__v2c_ipc_handle.write_offset = 0;
	}
	if (__v2c_ipc_handle.write_offset == __v2c_ipc_handle.read_offset) {
		printf("[%d] v2c ipc cache array full!\n", __LINE__);
		assert(0);//full
	}
	return 0;
}

static
int __read_event(unsigned char *p_event)
{
	if (__v2c_ipc_handle.read_offset == __v2c_ipc_handle.write_offset) {
		return -1;
	}
	*p_event = __v2c_ipc_handle.__ipc_ringbuff[__v2c_ipc_handle.read_offset];
	if (__v2c_ipc_handle.read_offset != V2C_IPC_RINGBUFF_SIZE - 1) {
		__v2c_ipc_handle.read_offset++;
	}
	else {
		__v2c_ipc_handle.read_offset = 0;
	}
	return 0;
}

// int v2c_ipc_register(unsigned char event, event_handle_t* event_handle)
// {
// 	for (int i = 0; i < EVENT_HANDLE_NUM_MAX; i++) {
// 		if (__event_manager_context[event][i] == 0) {
// 			__event_manager_context[event][i] = event_handle;
// 			return 0;
// 		}
// 	}

// 	assert(0);
// 	return -1;
// }

int v2c_ipc_write(unsigned char event)
{
	int ret = 0;

	ret = __append_event(event);
	if (ret != 0) {

	}
	
	return ret;
}

int v2c_ipc_read(unsigned char *p_event)
{
	return __read_event(p_event);
}
	