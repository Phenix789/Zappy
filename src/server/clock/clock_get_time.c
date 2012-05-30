/*
** clock_get_time.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 18:47:48 2012 quentin duval
** Last update Wed May 30 19:34:32 2012 quentin duval
*/

#include	"clock.h"

struct timeval	*clock_get_time()
{
  t_clock	*clock;

  clock = get_clock();
  clock_set_time_to_current(&clock->current);
  return (&(clock->current));
}
