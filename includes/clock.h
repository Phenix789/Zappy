/*
** clock.h for zappy in /home/duval_q//Documents/projects/zappy/includes
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 10:04:53 2012 quentin duval
** Last update Mon Jun 11 19:17:13 2012 quentin duval
*/

#ifndef __CLOCK_H__
#define	__CLOCK_H__

#include	<sys/time.h>
#include	<stdbool.h>

typedef	struct	s_clock
{
  struct timeval	timeout;
  struct timeval	begin;
  struct timeval	current;
  unsigned int		frequency;
} t_clock;

bool		clock_init();
void		clock_destroy();
t_clock		*get_clock();

bool		clock_set_frequency(unsigned int freq);
void		clock_move_date(struct timeval *time, unsigned int next);
struct timeval	*clock_get_timeout(struct timeval *start, unsigned int time);
int		clock_compare(struct timeval *time1, struct timeval *time2);
void		clock_set_time_to_current(struct timeval *time);
struct timeval	*clock_get_time();
void		time_unit_to_timeval(struct timeval *time, unsigned int unit);
unsigned int	timeval_to_time_unit(struct timeval *time);
unsigned int	clock_get_remaining_time(struct timeval *time,
					 unsigned int action_dur);

#endif
