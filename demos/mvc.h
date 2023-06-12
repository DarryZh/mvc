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
EXPORT_DATA_MODEL(clock, clock_data_model_t)
EXPORT_DATA_MODEL(alarm1, alarm1_data_model_t)
EXPORT_DATA_MODEL(alarm2, alarm2_data_model_t)
EXPORT_DATA_MODEL(alarm3, alarm3_data_model_t)
EXPORT_DATA_MODEL(alarm4, alarm4_data_model_t)
EXPORT_DATA_MODEL(cooler, cooler_data_model_t)

#endif
