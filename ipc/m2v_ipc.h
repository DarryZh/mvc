#ifndef __M2V_IPC_H__
#define __M2V_IPC_H__

#define M2V_IPC_RINGBUFF_SIZE				16

int m2v_ipc_write(unsigned char event);

int m2v_ipc_read(unsigned char* p_event);

#endif
