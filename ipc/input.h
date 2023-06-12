#ifndef __INPUT_IPC_H__
#define __INPUT_IPC_H__

#define INPUT_IPC_RINGBUFF_SIZE				16

int input_ipc_write(unsigned char event);

int input_ipc_read(unsigned char* p_event);

#endif
