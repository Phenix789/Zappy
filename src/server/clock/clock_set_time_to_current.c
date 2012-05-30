/*
** clock_tick.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:18:09 2012 quentin duval
** Last update Wed May 30 19:38:35 2012 quentin duval
*/

#include	<sys/time.h>
#include	<stdlib.h>

#include	"clock.h"

void	clock_set_time_to_current(struct timeval *time)
{
  gettimeofday(time , NULL);
}
