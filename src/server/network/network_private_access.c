/*
** network_private_fd_read.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 08:03:53 2012 quentin duval
** Last update Thu May 31 18:51:04 2012 quentin duval
*/

#include	"in_network.h"

void		execute_from_socket(void *data)
{
  t_socket              *socket;

  socket = (t_socket*)data;
  socket->read(socket, socket->param);
}

void			execute_from_listener(void *data)
{
  t_listener            *listener;
  t_socket		*sock;

  if (!(sock = malloc(sizeof(*sock))))
    return;
  sock->length = sizeof(sock->addr);
  listener = (t_listener*)data;
  if ((sock->fd = accept(listener->socket->fd, (SOCKADDR *) &sock->addr, &sock->length) < 0))
      return;
  (*listener->create)(sock);
}

SOCKET		extract_from_socket(void *data)
{
  t_socket              *socket;

  socket = (t_socket*)data;
  return (socket->fd);
}

SOCKET           extract_from_listener(void *data)
{
  t_listener            *listener;

  listener = (t_listener*)data;
  return (listener->socket->fd);
}
