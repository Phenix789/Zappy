/*
** network_listen.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/net
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 04:54:49 2012 quentin duval
** Last update Tue May 29 07:14:27 2012 quentin duval
*/

#include	"network.h"

#ifdef	_WIN32

#elif defined (linux)
# include	<sys/select.h>
#endif

void			setfd_list(t_list *list, fd_set *set)
{
  t_list_iterator       *it;
  int			ret;
  t_socket		*tmp;
  t_network		*network;

  network = get_network();
  it = list_iterator_begin(list);
  while (ret != EXIT_FAILURE)
    {
      tmp = (t_socket*)list_iterator_get(it);
      if (tmp->fd >= network->nfds)
	network->nfds = tmp->fd;
      FD_SET(tmp->fd, set);
      ret = list_iterator_next(it);
    }
  list_iterator_destroy(it);
}

void			setfd(fd_set *set)
{
  t_network		*network;

  network = get_network();
  FD_ZERO(set);
  setfd_list(network->read, set);
  setfd_list(network->listened, set);
}

int			network_listen()
{
  fd_set		set;
  struct timeval	timeout;
  t_network		*network;
  int			ret;

  network = get_network();
  timeout.tv_sec = 0;
  timeout.tv_usec = network->usec_timeout;

  ret = (select(network->nfds, &set, NULL, NULL, &timeout));
  network->nfds = 0;
  return (ret);
}
