/*
** network.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 03:54:36 2012 quentin duval
** Last update Thu May 31 21:59:02 2012 quentin duval
*/

#include		"network.h"
#include		"logger.h"

static t_network	*g_network = NULL;

bool			network_init()
{
  t_network		*network;

  logger_message("[NETWORK] starting network service");
  if (network_create() == false)
    return (false);
  network = get_network();
  network->nfds = 0;
  network->usec_timeout = 0;
  logger_message("[NETWORK] service started");
  return (true);
}

bool			network_create()
{
  logger_debug("[NETWORK] beginning allocation");
  if (!(g_network = malloc(sizeof(*g_network))))
    return (false);
  logger_debug("[NETWORK] allocation of main object... ok");
  if (!(g_network->listened = list_create()))
    return (false);
  logger_debug("[NETWORK] allocation of listening list... ok");
  if (!(g_network->read = list_create()))
    return (false);
  logger_debug("[NETWORK] allocation of reading list... ok");
  logger_debug("[NETWORK] allocation complete");
  return (true);
}

bool			network_destroy()
{
  t_network		*network;

  network = get_network();
  //close les sockets
  list_free(network->listened);
  list_free(network->read);
  free(network->listened);
  free(network->read);
  return (true);
}

t_network		*get_network()
{
  if (!g_network)
    logger_error("[NETWORK] network not initialised");
  return (g_network);
}
