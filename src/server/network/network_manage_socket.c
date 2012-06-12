/*
** network_socket.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:18:53 2012 quentin duval
** Last update Tue Jun 12 17:56:06 2012 quentin duval
*/

#include	"network.h"

extern t_network	*g_network;

bool    network_add_socket(t_socket *socket,
                           t_nt_read_cb callback,
                           void *param)
{
  if (!socket || !callback || !g_network)
    return (false);
  socket->read = callback;
  socket->param = param;
  list_add_begin(g_network->read, (void *)socket);
  return (true);
}

bool	network_del_socket(t_socket *socket)
{
  if (!socket || !g_network)
    return (true);
  list_pop(g_network->read, (void *)socket);
  return (true);
}
