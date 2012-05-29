/*
** clock.h for zappy in /home/duval_q//Documents/projects/zappy/includes
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:04:53 2012 quentin duval
** Last update Tue May 29 10:34:11 2012 quentin duval
*/

#ifndef __CLOCK_H__
#define	__CLOCK_H__

typedef	struct	s_clock
{
  unsigned long	timer_begin;
  unsigned int	speed;
  unsigned int	cycle;
  unsigned long	nb_cycle;
} t_clock;

t_clock		*clock_create();
void		clock_init(t_clock *);
void		clock_destroy();
void		clock_set_speed(int speed);
t_clock		*get_clock();

unsigned long	get_tick();

int		clock_turn_to_play();
void		clock_turn_played();
void		clock_wait();
unsigned long	clock_turn();

#endif
