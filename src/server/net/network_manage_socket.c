/*
** network_socket.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:18:53 2012 quentin duval
** Last update Tue May 29 05:34:01 2012 quentin duval
*/

#include	"network.h"

bool    network_add_socket(t_socket *socket,
                           t_nt_read_cb callback,
                           void *param)
{
  t_network     *network;

  network = get_network();
  socket->read = callback;
  socket->param = param;
  list_add_begin(network->read, (void *)socket);
  return (true);
}

bool	network_del_socket(t_socket *socket)
{
  t_network	*network;

  network = get_network();
  list_pop(network->read, (void *)socket);
  return (true);
}
