/*
** network_listen.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:54:49 2012 quentin duval
** Last update Wed May 30 21:43:45 2012 damien vezant
*/

#include	"network.h"
#include	"in_network.h"

#ifdef	_WIN32

#elif defined (linux)
# include	<sys/select.h>
#endif

static void		setfd_list(t_list *list,
				   fd_set *set,
				   SOCKET (*extract)(void *))
{
  t_list_iterator       *it;
  int			ret;
  void			*tmp;
  t_network		*network;

  network = get_network();
  it = list_iterator_begin(list);
  while (ret != EXIT_FAILURE)
    {
      tmp = (t_socket*)list_iterator_get(it);
      if (extract(tmp) >= network->nfds)
	network->nfds = extract(tmp);
      FD_SET(extract(tmp), set);
      ret = list_iterator_next(it);
    }
  list_iterator_destroy(it);
}

static void   		setfd(fd_set *set)
{
  t_network		*network;

  network = get_network();
  FD_ZERO(set);
  setfd_list(network->read, set, &extract_from_socket);
  setfd_list(network->listened, set, &extract_from_listener);
}

static void	find_speaker(fd_set *set,
			     t_list *list,
			     SOCKET (*extract)(void *),
			     void (*execute)(void *))
{
  t_list_iterator       *it;
  int                   ret;
  void			*tmp;
  /*t_network             *network;*/

  /*network = get_network();*/
  it = list_iterator_begin(list);
  while (ret != EXIT_FAILURE)
    {
      tmp = list_iterator_get(it);
      if (FD_ISSET(extract(tmp), set))
	execute(tmp);
      ret = list_iterator_next(it);
    }
  list_iterator_destroy(it);
}

int			network_listen(struct timeval *timeout)
{
  fd_set		set;
  t_network		*network;
  int			ret;

  network = get_network();
  setfd(&set);
  ret = (select(network->nfds, &set, NULL, NULL, timeout));
  if (ret > 0)
    {
      find_speaker(&set,
		   network->read,
		   &extract_from_socket,
		   &execute_from_socket);
      find_speaker(&set,
                   network->read,
                   &extract_from_listener,
                   &execute_from_listener);
    }
  network->nfds = 0;
  return (ret);
}
