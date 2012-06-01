/*
** clock_move_date.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 17:52:17 2012 quentin duval
** Last update Fri Jun  1 18:00:59 2012 quentin duval
*/

#include	"clock.h"
#include	"time_utils.h"
#include	"logger.h"

void			clock_move_date(struct timeval *time,
					unsigned int next)
{
  struct timeval	tmp;

  time_unit_to_timeval(&tmp, next);
  logger_verbose("move date %lu:%lu : %lu:%lu later",
		 time->tv_sec,
		 time->tv_usec,
		 tmp.tv_sec,
		 tmp.tv_usec);
  timeval_add(time, &tmp, time);
}
