/*
** network_socket.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 07:15:26 2012 quentin duval
** Last update Tue Jun 12 18:14:37 2012 quentin duval
*/

#include	"network.h"
#include	"logger.h"

extern t_network	*g_network;

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
  if (!g_network || !sock)
    return (NULL);
  g_network->opened_socket++;
  if ((sock->fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == SOCKET_ERROR)
    {
      free(sock);
      return (NULL);
    }
  sock->length = sizeof(sock->addr);
  return (sock);
}

void		listener_close(t_listener *listener)
{
  if (!listener || !g_network)
    return;
  if (listener)
    socket_close(listener->socket);
}

void		socket_close(t_socket *socket)
{
  if (!socket || !g_network)
    return;
  logger_verbose("[NETWORK] close socket %d", socket->fd);
  g_network->closed_socket++;
  if (socket)
    closesocket(socket->fd);
}

void	free_socket(t_socket *socket)
{
  free(socket);
}
