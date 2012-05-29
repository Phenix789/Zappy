/*
** clock_tick.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:18:09 2012 quentin duval
** Last update Tue May 29 10:36:55 2012 quentin duval
*/

#include	<sys/time.h>
#include	<stdlib.h>

#include	"clock.h"

unsigned long		get_tick()
{
  unsigned long int     tick;
  struct timeval	timeval_tick;

  gettimeofday(&timeval_tick, NULL);
  tick = timeval_tick.tv_sec * 1000;
  tick += timeval_tick.tv_usec / 1000;
  return (tick);
}
