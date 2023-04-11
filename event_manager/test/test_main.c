#include <stdio.h>
#include <time.h>
#include "event_manager.h"

event_handle_t event_handle1 = { .task_id = TASK1};
event_handle_t event_handle2 = { .task_id = TASK2 };
event_handle_t event_handle3 = { .task_id = TASK3 };

int main(void** args) 
{
	event_manager_init();

	event_register(EVENT1, &event_handle1);
	event_register(EVENT2, &event_handle1);
	event_register(EVENT3, &event_handle1);

	event_register(EVENT1, &event_handle2);
	event_register(EVENT2, &event_handle2);
	event_register(EVENT3, &event_handle2);

	event_register(EVENT1, &event_handle3);
	event_register(EVENT2, &event_handle3);
	event_register(EVENT3, &event_handle3);

	//int i = 0;
	//do{
	//	async_event(EVENT1);
	//	i++;
	//}while (i < 10);

	//async_event(EVENT1);
	//async_event(EVENT2);
	//async_event(EVENT3);

	unsigned char t_event;
	int ret;
	for (int i = 0; i < EVENT_MAX+1; i++) {
		ret = await_event(&t_event, &event_handle1);
		if (ret == 0) {
			printf("[%d] %d\n", __LINE__, t_event);
		}
		else {
			printf("[%d] await fail!\n", __LINE__);
		}
	}
	
	for (int i = 0; i < EVENT_MAX+1; i++) {
		ret = await_event(&t_event, &event_handle2);
		if (ret == 0) {
			printf("[%d] %d\n", __LINE__, t_event);
		}
		else {
			printf("[%d] await fail!\n", __LINE__);
		}
	}

	for (int i = 0; i < EVENT_MAX+1; i++) {
		ret = await_event(&t_event, &event_handle3);
		if (ret == 0) {
			printf("[%d] %d\n", __LINE__, t_event);
		}
		else {
			printf("[%d] await fail!\n", __LINE__);
		}
	}
	return 0;
}