/*
** clock_speed.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/clock
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:13:35 2012 quentin duval
** Last update Tue May 29 10:35:41 2012 quentin duval
*/

#include	"clock.h"

void		clock_set_speed(int speed)
{
  t_clock	*clock;

  if (speed == 0)
    speed = 1;
  clock = get_clock();
  clock->speed = speed;
  clock->cycle = 1000 / speed;
}
