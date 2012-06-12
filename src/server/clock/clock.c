/*
** clock.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:03:10 2012 quentin duval
** Last update Tue Jun 12 16:27:57 2012 quentin duval
*/

#include	<stdlib.h>
#include	<stdbool.h>

#include	"clock.h"
#include	"time_utils.h"
#include	"logger.h"

static t_clock	*g_clock = NULL;

static int	clock_create()
{
  if (g_clock)
    return (0);;
  if (!(g_clock = malloc(sizeof(*g_clock))))
    return (-1);
  return (0);
}

bool	clock_init()
{
  if (clock_create() < 0)
      return (false);
  g_clock->frequency = 1;
  clock_set_time_to_current(&g_clock->begin);
  timeval_modif(&g_clock->timeout, 0, 0);
  logger_message("[CLOCK] service started");
  return (true);
}

void	destroy_clock()
{
  free(g_clock);
}

t_clock	*get_clock()
{
  return (g_clock);
}

bool	clock_set_frequency(unsigned int freq)
{
  if (freq)
    {
      logger_message("[CLOCK] game frequency set to %ld", freq);
      g_clock->frequency = freq;
      return (true);
    }
  else
    {
      logger_error("[CLOCK] '0' is not a valid frequency, even for slowpoke");
      return (false);
    }
}
