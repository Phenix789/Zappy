/*
** clock_get_remaining_time.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 20:15:11 2012 quentin duval
** Last update Thu Jun 14 13:51:46 2012 quentin duval
*/

#include	"clock.h"
#include	"time_utils.h"

unsigned int    clock_get_remaining_time(struct timeval *time,
					 unsigned int action_dur)
{
  struct timeval        end_date;
  struct timeval	remaining;

  if (!time)
    return (0);
  timeval_copy(&end_date, time);
  clock_move_date(&end_date, action_dur);
  timeval_diff(&remaining, &end_date, clock_get_time());
  return (timeval_to_time_unit(&remaining));
}
