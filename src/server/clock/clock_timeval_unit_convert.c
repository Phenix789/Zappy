/*
** clock_timeval_unit_convert.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 18:49:40 2012 quentin duval
** Last update Fri Jun  1 20:56:23 2012 quentin duval
*/

#include	"clock.h"
#include	"logger.h"

void            time_unit_to_timeval(struct timeval *time, unsigned int unit)
{
  t_clock	*clock;

  clock = get_clock();
  time->tv_sec = unit / clock->frequency;
  unit = unit % clock->frequency;
  time->tv_usec = (unit * 1000000) / clock->frequency;
}

unsigned int    timeval_to_time_unit(struct timeval *time)
{
  unsigned int	res;
  t_clock	*clock;

  clock = get_clock();
  res = time->tv_sec * clock->frequency;
  res += (time->tv_usec * clock->frequency) / 1000000;
  return res;
}
