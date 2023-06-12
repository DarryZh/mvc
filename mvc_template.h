#ifndef __MVC_H__
#define __MVC_H__

#include "event_manager.h"
#include "event_def.h"

#include "__data_model_impl.h"
#include "__view_impl.h"
#include "__controll_impl.h"

#include "v2c_ipc.h"
#include "m2v_ipc.h"

#include "data_model_templete.h"


int mvc_raw_entry(mvc_task_handle_t *ptThis);

// USE 'EXPORT_DATA_MODEL(model name, model type)' to EXPORT your data model


#endif
