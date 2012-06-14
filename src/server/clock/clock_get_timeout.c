/*
** clock_turn.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 10:22:12 2012 quentin duval
** Last update Thu Jun 14 14:24:36 2012 quentin duval
*/

#include	<stdlib.h>

#include	"clock.h"
#include	"time_utils.h"
#include	"logger.h"

struct timeval		*clock_get_timeout(struct timeval *begin,
					   unsigned int unit_time)
{
  t_clock		*clock;
  struct timeval	end_date;

  clock = get_clock();
  if (!begin)
    return (NULL);
  timeval_copy(&end_date, begin);
  clock_move_date(&end_date, unit_time);
  logger_debug("[CLOCK] begin : %lu:%lu\nend : %lu:%lu",
		 begin->tv_sec, begin->tv_usec,
		 end_date.tv_sec, end_date.tv_usec);
  timeval_diff(&clock->timeout, &end_date, clock_get_time());
  logger_debug("[CLOCK] With %d units of time, timeout is set to %lu:%lu",
	       unit_time,
	       clock->timeout.tv_sec,
	       clock->timeout.tv_usec);
  return (&(clock->timeout));
}
