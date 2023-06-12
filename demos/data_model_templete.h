#ifndef __DATA_MODEL_TEMPLETE_H__
#define __DATA_MODEL_TEMPLETE_H__

#include <stdbool.h>
#include "__data_model_impl.h"

typedef struct
{
	char hour;
	char min;
} clock_data_model_t;

typedef struct
{
	char hour;
	char min;
	bool invaild;
} alarm1_data_model_t;

typedef struct
{
	char hour;
	char min;
	bool invaild;
} alarm2_data_model_t;

typedef struct
{
	char hour;
	char min;
	bool invaild;
} alarm3_data_model_t;

typedef struct
{
	char hour;
	char min;
	bool invaild;
} alarm4_data_model_t;

typedef struct
{
	unsigned char level;
} cooler_data_model_t;

#endif
