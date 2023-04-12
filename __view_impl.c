#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "__view_impl.h"

//#pragma weak view_init

void view_init(void) {

}

#undef this
#define this	(*ptThis)

int view_task(view_task_handle_t *ptThis) {
	enum {
		START = 0,
		LOOP = 1
	};
	unsigned char event;
	int ret;

	switch (this.chState) {
	case START:
		view_init();
		this.chState++;
		//break;
	case LOOP:
		//receive message from model
		ret = try_receive_event_async(&event, &this.event_handle);
		if (ret == 0) {
			printf("[view] try %d\r\n", event);
		}
		break;
	}

	return 0;
}
