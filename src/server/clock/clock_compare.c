/*
** clock_compare.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Wed May 30 18:42:42 2012 quentin duval
** Last update Wed Jun 13 20:19:03 2012 quentin duval
*/

#include	"clock.h"

int	clock_compare(struct timeval *date1, struct timeval *date2)
{
  if (date1->tv_sec != date2->tv_sec)
    {
    if (date1->tv_sec > date2->tv_sec)
      return (1);
    else
      return (-1);
    } 
  else
    {
      if (date1->tv_usec > date2->tv_usec)
	return (1);
      else if (date1->tv_usec < date2->tv_usec)
	return (-1);
      else
	return (0);
    }
}
