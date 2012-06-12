/*
** network_listen.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 04:54:49 2012 quentin duval
** Last update Tue Jun 12 18:19:45 2012 quentin duval
*/

#include	<stdio.h>

#include	"network.h"
#include	"in_network.h"
#include	"logger.h"

#ifdef	_WIN32

#elif defined (linux)
# include	<sys/select.h>
#endif

extern t_network	*g_network;

static void		flush_list()
{
  t_socket		*socket;

  while ((!list_empty(g_network->destroy)))
    {
      socket =  list_get_begin(g_network->destroy);
      socket_close(socket);
      network_del_socket(socket);
      list_pop_begin(g_network->destroy);
    }
}

static void		setfd_list(t_list *list,
				   fd_set *set,
				   SOCKET (*extract)(void *))
{
  t_list_iterator       *it;
  int			ret;
  void			*tmp;

  if (!list || !set || !extract || !g_network)
    return;
  it = list_iterator_begin(list);
  ret = (list_empty(list))?EXIT_FAILURE:EXIT_SUCCESS;
  while (ret != EXIT_FAILURE)
    {
      tmp = list_iterator_get(it);
      if (extract(tmp) >= g_network->nfds)
	g_network->nfds = extract(tmp) + 1;
      logger_verbose("[NETWORK] adding fd %d", extract(tmp));
      FD_SET(extract(tmp), set);
      ret = list_iterator_next(it);
    }
  list_iterator_destroy(it);
}

static void   		setfd(fd_set *set)
{
  if (!set || !g_network)
    return;
  FD_ZERO(set);
  setfd_list(g_network->read, set, &extract_from_socket);
  setfd_list(g_network->listened, set, &extract_from_listener);
}

static void	find_speaker(fd_set *set,
			     t_list *list,
			     SOCKET (*extract)(void *),
			     void (*execute)(void *))
{
  t_list_iterator       *it;
  int                   ret;
  void			*tmp;

  if (!set || !list || !extract || !execute)
    return;
  it = list_iterator_begin(list);
  ret = (list_empty(list))?EXIT_FAILURE:EXIT_SUCCESS;
  while (ret != EXIT_FAILURE)
    {
      tmp = list_iterator_get(it);
      if (FD_ISSET(extract(tmp), set) && tmp)
	{
	  logger_verbose("[NETWORK] message from fd : %d", extract(tmp));
	  ret = list_iterator_next(it);
	  (*execute)(tmp);
	}
      else
	ret = list_iterator_next(it);
    }
  flush_list();
  list_iterator_destroy(it);
}

int			network_listen(struct timeval *timeout)
{
  fd_set		set;
  int			ret;

  flush_list();
  setfd(&set);
  if (timeout)
    logger_debug("[NETWORK] waiting for next action in %lu:%lu",
	   timeout->tv_sec,
	   timeout->tv_usec);
  else
    logger_debug("[NETWORK] waiting for extern action. nothing planified");
  if ((ret = (select(g_network->nfds, &set, NULL, NULL, timeout))) > 0)
    {
      find_speaker(&set,
		   g_network->read,
		   &extract_from_socket,
		   &execute_from_socket);
      find_speaker(&set,
		   g_network->listened,
		   &extract_from_listener,
		   &execute_from_listener);
    }
  g_network->nfds = 0;
  return (ret);
}
