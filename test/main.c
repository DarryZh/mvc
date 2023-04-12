#include <stdio.h>
#include <stdbool.h>

#include "mvc.h"
#include "data_model_templete.h"

EXPORT_DATA_MODEL(motor, motor_data_model_t)

int main(void)
{
	printf("hello mvc!\n");

	motor_data_model_t tmp = DATA_MODEL_GET(motor);
	printf("%d\n", tmp.data);
	//loop
	while (true) {

		mvc_raw_entry();
	}

	return 0;
}
