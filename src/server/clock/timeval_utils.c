/*
** timeval_utils.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 19:40:21 2012 quentin duval
** Last update Thu Jun 14 21:02:42 2012 quentin duval
*/

#include	<sys/time.h>

#include	"time_utils.h"
#include	"logger.h"

void		timeval_add(struct timeval *res,
			    struct timeval *date1,
			    struct timeval *date2)
{
  unsigned int	tmp;

  res->tv_sec = date1->tv_sec + date2->tv_sec;
  res->tv_usec = date1->tv_usec + date2->tv_usec;
  if (res->tv_usec > 1000000)
    {
      tmp = res->tv_usec;
      res->tv_usec = tmp % 1000000;
      res->tv_sec += tmp / 1000000;
    } 
}

void    timeval_copy(struct timeval *dst,
                     struct timeval *src)
{
  dst->tv_sec = src->tv_sec;
  dst->tv_usec = src->tv_usec;
}

void    timeval_diff(struct timeval *res,
                     struct timeval *date1,
                     struct timeval *date2)
{
  res->tv_sec = 0;
  res->tv_usec = 0;
  if (date1->tv_sec >= date2->tv_sec)
    {
      res->tv_sec = date1->tv_sec - date2->tv_sec;
      if (date1->tv_usec >= date2->tv_usec)
	res->tv_usec = date1->tv_usec - date2->tv_usec;
      else
	{
	  if (res->tv_sec > 0)
	    {
	      res->tv_sec = res->tv_sec - 1;
	      res->tv_usec = date2->tv_usec - date1->tv_usec;
	    }
	}
    }
}

void    timeval_modif(struct timeval* date,
                      unsigned int sec,
                      unsigned int usec)
{
  date->tv_sec = sec;
  date->tv_usec = usec;
}
