/*
** clock_turn.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:22:12 2012 quentin duval
** Last update Wed May 30 19:37:11 2012 quentin duval
*/

#include	<stdlib.h>

#include	"clock.h"
#include	"time_utils.h"

struct timeval		*clock_get_timeout(struct timeval *begin,
					   unsigned int unit_time)
{
  t_clock		*clock;
  struct timeval	end_date;
  struct timeval	current_date;

  clock = get_clock();
  if (!begin)
    return (NULL);
  timeval_copy(&end_date, begin);
  clock_move_date(&end_date, unit_time);
  timeval_copy(&current_date, clock_get_time());
  timeval_diff(&clock->timeout, &end_date, &current_date);
  return (&(clock->timeout));
}
