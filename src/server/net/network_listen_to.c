/*
** network_listen.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:30:59 2012 quentin duval
** Last update Tue May 29 08:06:44 2012 quentin duval
*/

# include	"network.h"

bool		network_listen_to(t_socket *socket,
				  int port,
				  t_nt_create_cb create)
{
  t_listener	*listener;

  socket->addr.sin_port = htons(port);
  socket->addr.sin_addr.s_addr = INADDR_ANY;
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
  return (true);
}