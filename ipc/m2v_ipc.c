#include <stdio.h>
#include <assert.h>
#include "m2v_ipc.h"

typedef struct {
	unsigned char __ipc_ringbuff[M2V_IPC_RINGBUFF_SIZE];
	unsigned char read_offset;
	unsigned char write_offset;
} m2v_ipc_handle_t;

static m2v_ipc_handle_t __m2v_ipc_handle = { 0 };

int m2v_ipc_init(void) 
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
	__m2v_ipc_handle.__ipc_ringbuff[__m2v_ipc_handle.write_offset] = event;
	if (__m2v_ipc_handle.write_offset != M2V_IPC_RINGBUFF_SIZE - 1) {
		__m2v_ipc_handle.write_offset++;
	}
	else {
		__m2v_ipc_handle.write_offset = 0;
	}
	if (__m2v_ipc_handle.write_offset == __m2v_ipc_handle.read_offset) {
		printf("[%d] m2v ipc cache array full!\n", __LINE__);
		assert(0);//full
	}
	return 0;
}

static
int __read_event(unsigned char *p_event)
{
	if (__m2v_ipc_handle.read_offset == __m2v_ipc_handle.write_offset) {
		return -1;
	}
	*p_event = __m2v_ipc_handle.__ipc_ringbuff[__m2v_ipc_handle.read_offset];
	if (__m2v_ipc_handle.read_offset != M2V_IPC_RINGBUFF_SIZE - 1) {
		__m2v_ipc_handle.read_offset++;
	}
	else {
		__m2v_ipc_handle.read_offset = 0;
	}
	return 0;
}

// int m2v_ipc_register(unsigned char event, event_handle_t* event_handle)
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

int m2v_ipc_write(unsigned char event)
{
	int ret = 0;

	ret = __append_event(event);
	if (ret != 0) {

	}
	
	return ret;
}

int m2v_ipc_read(unsigned char *p_event)
{
	return __read_event(p_event);
}
	