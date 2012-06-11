/*
** network_socket_destroy.c for zappy in /home/duval_q//Documents/projects/zappy-2015-2014s-duval_q/src/server/network
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Mon Jun  4 07:51:20 2012 quentin duval
** Last update Mon Jun  4 09:03:15 2012 quentin duval
*/

#include	"network.h"
#include	"list.h"

void		network_close_socket_async(t_socket *socket)
{
  t_network	*network;

  network = get_network();
  list_add_begin(network->destroy, socket);
}
