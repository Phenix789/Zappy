/*
** clock.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:03:10 2012 quentin duval
** Last update Wed May 30 19:39:57 2012 quentin duval
*/

#include	<stdlib.h>

#include	"clock.h"
#include	"time_utils.h"

static t_clock	*clock;

void	clock_init(t_clock *clock)
{
  clock_set_frequency(1);
  clock_set_time_to_current(&clock->begin);
  timeval_modif(&clock->timeout, 0, 0);
}

t_clock	*clock_create()
{
  if (!(clock = malloc(sizeof(*clock))))
    return (NULL);
  clock_init(clock);
  return (clock);
}

void	destroy_clock()
{
  free(clock);
}

t_clock	*get_clock()
{
  return (clock);
}

void	clock_set_frequency(unsigned int freq)
{
  clock->frequency = freq;
}
