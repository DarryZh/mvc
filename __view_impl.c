#include <stdio.h>
#include <string.h>

#include "ss_lcd.h"
#include "log.h"

#include "mvc.h"
#include "m2v_ipc.h"
#include "input.h"

//timer_handler is ui loop, config it
#include "obj.h"
#include "ui_timer.h"
#include "disp.h"

#define NEXT_VIEW_DataModel(index)	index++

extern const int DataModelTab$$Base;
extern const int DataModelTab$$Limit;

__DataModel_BASE_t *_DataModel_table_begin  = NULL;
__DataModel_BASE_t *_DataModel_table_end    = NULL;

static void DataModel_Table_init(const void *begin, const void *end)
{
    _DataModel_table_begin = (__DataModel_BASE_t*) begin;
    _DataModel_table_end = (__DataModel_BASE_t *) end;
}

// __WEAK header file, config it
#include "board.h"

__WEAK void view_init(void) 
{

}
__WEAK void view_register_init(void)
{

}
__WEAK void input_2_user_request(unsigned int event)
{

}


#undef this
#define this	(*ptThis)

int view_sub_task(view_task_handle_t *ptThis) {
	enum {
		START = 0,
		LOOP = 1
	};
	unsigned char event;
	int ret;
    const char *tmp_name;

	switch (this.chState) {
	case START:
		view_register_init();
		DataModel_Table_init(&DataModelTab$$Base, &DataModelTab$$Limit);
		ui_init();
		view_init();
		disp_init();
		this.chState++;
		//break;
	case LOOP:
		{
			__DataModel_BASE_t *index;

			//receive message from model
			ret = m2v_ipc_read(&event);
			if (ret == 0) {
				// LOG_D("[view][mvc ipc] receive %d", event);
				for (index = _DataModel_table_begin;
						index < _DataModel_table_end;
						NEXT_VIEW_DataModel(index))
				{
					if(index->base.index == event) {
						if((*index->view_cb) != NULL) {
							(*((base_view_cb_func_t *)(index->view_cb)))(index->ctx);
							LOG_D("[view ipc][update data model] %s", index->base.name);
						}
						
						break;
					}
				}
			} 

			//receive message from input
			ret = input_ipc_read(&event);
			if (ret == 0) {
				LOG_D("[view][mvc ipc] receive %d", event);
				input_2_user_request(event);
			} 

			//timer_handler is ui loop, config it
			timer_handler();
			
			break;
		}
	}

	return 0;
}
