/*
** network_socket.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 07:15:26 2012 quentin duval
** Last update Thu May 31 17:18:51 2012 quentin duval
*/

#include	"network.h"

t_socket	*socket_create()
{
  t_socket	*socket;

  if (!(socket = (malloc(sizeof(t_socket)))))
    return (NULL);
  socket_init(socket);
  return (socket);
}

t_socket	*socket_init(t_socket *sock)
{
  if ((sock->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR)
    {
      free(sock);
      return (NULL);
    }
  sock->length = sizeof(sock->addr);
  return (sock);
}

void	socket_close(t_socket *socket)
{
  closesocket(socket->fd);
}

void	free_socket(t_socket *socket)
{
  free(socket);
}
