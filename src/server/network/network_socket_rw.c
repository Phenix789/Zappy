/*
** network_socket_rw.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 07:30:05 2012 quentin duval
** Last update Sat Jun  2 10:56:56 2012 quentin duval
*/

#include	"network.h"

int	socket_read(t_socket *socket, void *buffer, int size)
{
  if (!socket || !buffer || size < 1)
    return (-1);
  return (recv(socket->fd, buffer, size, 0));
}

int	socket_write(t_socket *socket, void *buffer, int size)
{
  if (!socket || !buffer || size < 1)
    return (-1);
  return (send(socket->fd, buffer, size, 0));
}
