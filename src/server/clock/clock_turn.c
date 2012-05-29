/*
** clock_turn.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:22:12 2012 quentin duval
** Last update Tue May 29 17:08:06 2012 quentin duval
*/

#include	"clock.h"

int		clock_turn_to_play()
{
  t_clock	*clock;
  int		turns;
  unsigned long	time;

  turns = 0;
  clock = get_clock();
  time = get_tick() - clock->timer_begin;
  while (time >= clock->cycle)
    {
      turns++;
      time = time - clock->cycle;
    }
  return (turns);
}

unsigned long	clock_turn()
{
  return (get_clock()->nb_cycle);
}

void		clock_turn_played()
{
  t_clock	*clock;
  unsigned long	time;

  clock = get_clock();
  clock->nb_cycle++;
  clock = get_clock();
  time = get_tick() - clock->timer_begin;
  clock->timer_begin = get_tick() - (time % clock->cycle);
}
