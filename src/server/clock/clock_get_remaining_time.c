/*
** clock_get_remaining_time.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 20:15:11 2012 quentin duval
** Last update Wed May 30 21:44:13 2012 damien vezant
*/

#include	"clock.h"
#include	"time_utils.h"

unsigned int    clock_get_remaining_time(struct timeval *time,
					 unsigned int action_dur)
{
  /*t_clock               *clock;*/
  struct timeval        end_date;
  struct timeval        current_date;
  struct timeval	remaining;

  /*clock = get_clock();*/
  if (!time)
    return (0);
  timeval_copy(&end_date, time);
  clock_move_date(&end_date, action_dur);
  timeval_copy(&current_date, clock_get_time());
  timeval_diff(&remaining, &end_date, &current_date);
  return (timeval_to_time_unit(&remaining));
}
