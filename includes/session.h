/*
** session.h for zappy in /home/kersuz_v//Zappy/includes
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 03:43:20 2012 vincent kersuzan
** Last update Thu May 31 22:01:25 2012 quentin duval
*/

#ifndef		SESSION_H_
# define	SESSION_H_

# include	"client.h"
# include	"list.h"
# include	"parser.h"
# include	"network.h"

typedef void	(*t_se_execute_cb) (void *, t_command *);

typedef struct		s_instruction_in
{
  int			length;
  char			*instruction;
  char			*mask;
  t_se_execute_cb	cb;
}			t_instruction_in;

typedef struct	s_instruction_out
{
  int		instruction;
  char		*mask;
}		t_instruction_out;

typedef struct	s_session
{
  t_list	in;
  t_list	out;
}		t_session;

void	session_connect(t_socket *new_sock);
int	session_send(t_client *client, char *mask, ...);
int	session_register_in(char *instruction, char *mask, t_se_execute_cb cb);
int	session_register_out(int instruction, char *mask);
void	session_treat_data(t_socket *socket, t_client *client);
bool	session_create(void);
bool	session_init(t_socket *listen, int port);
int	session_destroy(void);
t_session	*session_get_session(void);

void session_execute(t_client *client, char *cmd);
void session_close(t_client *client);
t_instruction_in *session_retrieve_command(char *command);

#endif	/*	SESSION_H_	*/
