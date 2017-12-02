//SOCKET_CLIENT_H
/*

pointer, pp
encapsulation : **handler

*/

#ifndef SOCKET_CLIENT_H
#define SOCKET_CLIENT_H

// avoid cpp name mangling, makes a function-name in C++ have 'C' linkage
#ifdef __cplusplus
extern "C" {
#endif

	// socket init
	int socket_client_init(void **handle);
	// socket send

	int socket_client_send(void *handle, unsigned char *buf, int buflen);
	// socket receive

	int socket_client_receive(void * handle, unsigned char * buf, int buflen);
	//socket release
	int socket_client_destroy(void * handle);

// 2nd
	// socket init
	int socket_client_init2(void **handle);
	// socket send

	int socket_client_send2(void *handle, unsigned char **buf, int buflen);
	// socket receive

	int socket_client_receive2(void * handle, unsigned char **buf, int buflen);
	//socket release
	int socket_client_destroy2(void * handle);

#ifdef __cplusplus
}
#endif


#endif