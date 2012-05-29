/*
** network_socket_connect.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 07:28:04 2012 quentin duval
** Last update Tue May 29 07:37:28 2012 quentin duval
*/

#include	"network.h"

bool    socket_connect(t_socket *socket, char *ip, int port)
{
  socket->addr.sin_family = AF_INET;
  socket->addr.sin_port = htons(port);
  if ((socket->addr.sin_addr.s_addr = inet_addr(ip)) == INADDR_NONE)
    return (false);
  if (connect(socket->fd,
              (SOCKADDR*)&socket->addr,
              socket->length) == SOCKET_ERROR)
    return (false);
  return (true);
}
