#ifndef __EVENT_MANAGER_H__
#define __EVENT_MANAGER_H__

#define EVENT_NUM_MAX				20
#define EVENT_HANDLE_NUM_MAX		6

#define	EVENT_CACHE_ARRAY_SIZE		10

typedef struct {
	unsigned char event_cache_array[EVENT_CACHE_ARRAY_SIZE];
	unsigned char read_offset;
	unsigned char write_offset;
} event_handle_t;


int event_register(unsigned char event, event_handle_t* event_handle);

int send_event_async(unsigned char event);

int try_receive_event_async(unsigned char* p_event, event_handle_t* handle);

#define send_event	send_event_async

#endif
