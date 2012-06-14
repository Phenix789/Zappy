/*
** network.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 03:54:36 2012 quentin duval
** Last update Tue Jun 12 18:47:03 2012 quentin duval
*/

#include		"network.h"
#include		"logger.h"

t_network	*g_network = NULL;

bool			network_init()
{
  logger_message("[NETWORK] starting network service");
  if (g_network)
    return (true);
  if (network_create() == false)
    {
      logger_error("[NETWORK] critical fail on allocation");
      return (false);
    }
  g_network->nfds = 0;
  g_network->usec_timeout = 0;
  g_network->opened_socket = 0;
  g_network->closed_socket = 0;
  logger_message("[NETWORK] service started");
  return (true);
}

bool			network_create()
{
  if (g_network)
    return (true);
  if (!(g_network = malloc(sizeof(*g_network))))
    return (false);
  if (!(g_network->listened = list_create()))
    return (false);
  if (!(g_network->destroy = list_create()))
    return (false);
  if (!(g_network->read = list_create()))
    return (false);
  logger_debug("[NETWORK] allocation ...ok");
  return (true);
}

bool			network_destroy()
{
  if (!g_network)
    return (true);
  logger_message("[NETWORK] Network destroy");
  list_foreach(g_network->listened, (feach) listener_close);
  list_foreach(g_network->read, (feach) socket_close);
  list_free(g_network->listened);
  list_free(g_network->read);
  logger_message("[NETWORK] destroyed : %lu socket not closed",
		 g_network->opened_socket - g_network->closed_socket);
  free(g_network->listened);
  free(g_network->destroy);
  free(g_network->read);
  free(g_network);
  g_network = NULL;
  return (true);
}
