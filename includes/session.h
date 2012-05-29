/*
** session.h for zappy in /home/kersuz_v//Zappy/includes
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 03:43:20 2012 vincent kersuzan
** Last update Tue May 29 04:05:24 2012 vincent kersuzan
*/

#ifndef		SESSION_H_
# define	SESSION_H_

# include	"parser.h"

typedef void	(*t_se_execute_cb) (void *, t_command *);

typedef struct	s_session
{
}		t_session;

int	session_send(t_client *client, char *mask, ...);
int	session_register_in(char *instruction, char *mask, t_se_execute_cb cb);
int	session_register_out(int instruction, char *mask);
int	session_treat_data(char *data, void *arg);
int	session_create(void);
int	session_destroy(void);

#endif	/*	SESSION_H_	*/
