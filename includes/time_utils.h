/*
** time_utils.h for zappy in /home/duval_q//Documents/projects/zappy/includes
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Wed May 30 17:41:25 2012 quentin duval
** Last update Wed May 30 19:33:33 2012 quentin duval
*/

#ifndef		TIME_UTILS_H_
# define	TIME_UTILS_H_

# include	<sys/time.h>

void	timeval_add(struct timeval *res,
		    struct timeval *date1,
		    struct timeval *date2);
void	timeval_copy(struct timeval *dst,
		     struct timeval *src);
void	timeval_diff(struct timeval *res,
		     struct timeval *date1,
		     struct timeval *date2);
void	timeval_modif(struct timeval* date,
		      unsigned int sec,
		      unsigned int usec);

#endif	/*	TIME_UTILS_H_	*/
