/*
** network_socket_destroy.c for zappy in /home/duval_q//Documents/projects/zappy-2015-2014s-duval_q/src/server/network
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Mon Jun  4 07:51:20 2012 quentin duval
** Last update Tue Jun 12 18:15:00 2012 quentin duval
*/

#include	"network.h"
#include	"list.h"
#include	"logger.h"

extern t_network	*g_network;

void		network_close_socket_async(t_socket *socket)
{
  if (!g_network)
    return;
  logger_debug("[NETWORK] required to die : %d", socket->fd);
  list_add_begin(g_network->destroy, socket);
}
