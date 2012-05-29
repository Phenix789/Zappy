/*
** clock.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:03:10 2012 quentin duval
** Last update Tue May 29 10:35:17 2012 quentin duval
*/

#include	<stdlib.h>

#include	"clock.h"

static t_clock	*clock;

void	clock_init(t_clock *clock)
{
  clock_set_speed(1);
  clock->timer_begin = get_tick();
  clock->nb_cycle = 0;
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
  
}

t_clock	*get_clock()
{
  return (clock);
}
