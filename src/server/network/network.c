/*
** network.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 03:54:36 2012 quentin duval
** Last update Thu May 31 18:29:04 2012 quentin duval
*/

#include		"network.h"

static t_network	*g_network;

bool			network_init()
{
  t_network		*network;

  if (network_create() == false)
    return (false);
  network = get_network();
  network->nfds = 0;
  network->usec_timeout = 0;
  return (true);
}

bool			network_create()
{
  t_network		*network;

  if (!(network = malloc(sizeof(t_network))))
    return (false);
  if (!(network->listened = list_create()))
    return (false);
  if (!(network->read = list_create()))
    return (false);
  g_network = network;
  return (true);
}

bool			network_destroy()
{
  t_network		*network;

  network = get_network();
  list_free(network->listened);
  list_free(network->read);
  free(network->listened);
  free(network->read);
  return (true);
}

t_network		*get_network()
{
  return (g_network);
}
