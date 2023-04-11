#include <stdio.h>
#include <stdbool.h>

#include "mvc.h"
#include "event_def.h"

event_handle_t task1_event_handle;
event_handle_t task2_event_handle;
event_handle_t task3_event_handle;

int main(void)
{
	unsigned char event_tmp;
	int ret;
	printf("hello mvc!\n");
	event_register(EVENT1, &task1_event_handle);
	event_register(EVENT2, &task2_event_handle);
	event_register(EVENT3, &task3_event_handle);

	send_event(EVENT1);
	send_event(EVENT2);
	send_event(EVENT3);
	//loop
	while (true) {
		ret = try_receive_event_async(&event_tmp, &task1_event_handle);
		if (ret == 0) {
			printf("try 1 %d\r\n", event_tmp);
		}
		ret = try_receive_event_async(&event_tmp, &task2_event_handle);
		if (ret == 0) {
			printf("try 2 %d\r\n", event_tmp);
		}
		ret = try_receive_event_async(&event_tmp, &task3_event_handle);
		if (ret == 0) {
			printf("try 3 %d\r\n", event_tmp);
		}
	}

	return 0;
}
