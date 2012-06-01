/*
** clock.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:03:10 2012 quentin duval
** Last update Fri Jun  1 17:55:42 2012 quentin duval
*/

#include	<stdlib.h>

#include	"clock.h"
#include	"time_utils.h"
#include	"logger.h"

static t_clock	*g_clock;

void	clock_init()
{
  clock_create();
  clock_set_frequency(1);
  clock_set_time_to_current(&g_clock->begin);
  timeval_modif(&g_clock->timeout, 0, 0);
}

void	clock_create()
{
  if (!(g_clock = malloc(sizeof(*g_clock))))
    return;
}

void	destroy_clock()
{
  free(g_clock);
}

t_clock	*get_clock()
{
  return (g_clock);
}

void	clock_set_frequency(unsigned int freq)
{
  logger_message("game frequency set to %ld", freq);
  g_clock->frequency = freq;
}
