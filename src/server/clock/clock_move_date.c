/*
** clock_move_date.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 17:52:17 2012 quentin duval
** Last update Wed May 30 19:38:17 2012 quentin duval
*/

#include	"clock.h"
#include	"time_utils.h"

void			clock_move_date(struct timeval *time,
					unsigned int next)
{
  struct timeval	tmp;

  time_unit_to_timeval(&tmp, next);
  timeval_add(time, &tmp, time);
}
