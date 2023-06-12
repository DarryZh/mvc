#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "mvc.h"
#include "board.h"

#undef this
#define this	(*ptThis)

__WEAK void extern_controll_event_handle(unsigned int event)
{

}

__WEAK void v2c_user_req_handle(unsigned int event)
{

}

int controll_sub_task(mvc_task_handle_t *ptThis) {
	enum {
		START = 0,
        REV_EVENT,
		LOOP
	};
	
	int ret;

	switch (this.chState) {
	case START:

		this.chState++;
		//break;
    case REV_EVENT:
		{
			unsigned int event;
			if(0 == try_recevice_event(&event, &(this.event_handle))){			// this is the extern event recevice entry, config it
				// printf("[%s][%d] rec event: %d\n", __FUNCTION__, __LINE__, event);
				extern_controll_event_handle(event);
				break;
			}
			this.chState++;
		}
        // break;
	case LOOP:
		{
			unsigned char event;
			//receive message from input
			ret = v2c_ipc_read(&event);
			if (ret == 0) {
				// LOG_D("[controll][mvc ipc] receive %d", event);
				v2c_user_req_handle(event);
			} 
            this.chState = REV_EVENT;
			break;
		}
	}

	return 0;
}
