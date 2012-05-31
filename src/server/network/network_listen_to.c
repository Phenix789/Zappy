/*
** network_listen.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:30:59 2012 quentin duval
** Last update Thu May 31 17:25:24 2012 quentin duval
*/

#include	<stdio.h>

# include	"network.h"

bool		network_listen_to(t_socket *socket,
				  int port,
				  t_nt_create_cb create)
{
  t_listener	*listener;

  socket->addr.sin_port = htons(port);
  socket->addr.sin_family = AF_INET;
  socket->addr.sin_addr.s_addr = INADDR_ANY;
  socket->length = (sizeof(socket->addr));
  if (bind(socket->fd,
	   (SOCKADDR *)&socket->addr,
	   socket->length) == SOCKET_ERROR)
    return (false);
  if (listen(socket->fd, MAX_CO) == SOCKET_ERROR)
    return (false);
  if (!(listener = malloc(sizeof(*listener))))
    return (false);
  listener->socket = socket;
  listener->create = create;
  if (socket->fd > get_network()->nfds)
    get_network()->nfds = socket->fd;
  list_add_begin(get_network()->listened, listener);
  printf("server is now listening at new interface at port : %d\n", port);
  return (true);
}
