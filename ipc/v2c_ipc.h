#ifndef __V2C_IPC_H__
#define __V2C_IPC_H__

#define V2C_IPC_RINGBUFF_SIZE				16

int v2c_ipc_write(unsigned char event);

int v2c_ipc_read(unsigned char* p_event);

#endif
