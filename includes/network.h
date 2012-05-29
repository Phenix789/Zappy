/**
 *
 *
 *
 */

#ifndef __NETWORK_H__
#define	__NETWORK_H__

typedef struct s_network
{

} t_network;

typedef struct s_socket
{

} t_socket;

typedef void (*ntcallback)(t_socket *, void *);

bool network_create();
bool network_destroy();

bool network_add_socket(t_socket *socket, ntcallback callback, void * param);
bool network_del_socket(t_socket *socket);
int network_listen();
bool network_listen_to(t_socket *socket, int port);

void network_set_*();

t_socket * socket_create();
t_socket * socket_init(t_socket * socket);
void socket_close(t_socket * socket);

bool socket_connect(t_socket *socket);

int socket_read(t_socket *soket, void *buffer, int size);
int socket_write(t_socket *socket, void *buffer, int size);

void socket_set_*();

#endif
