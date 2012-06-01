/*
** session.h for zappy in /home/kersuz_v//Zappy/includes
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 03:43:20 2012 vincent kersuzan
** Last update Fri Jun  1 16:42:10 2012 quentin duval
*/

#ifndef		SESSION_H_
# define	SESSION_H_

# include	<stdarg.h>

# include	"client.h"
# include	"list.h"
# include	"parser.h"
# include	"network.h"

typedef void	(*t_se_execute_cb) (t_client *, t_command *);

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

/*
** interface
*/

int	session_send(t_client *client, char *mask, ...);
int	session_register_in(char *instruction, char *mask, t_se_execute_cb cb);
int	session_register_out(int instruction, char *mask);
void    session_treat_data(t_socket *socket, t_client *client);
bool	session_create(void);
bool    session_init(t_socket *listen, int port);
int	session_destroy(void);
void	session_execute(t_client *client, char *cmd);
void	session_close(t_client *client);
void	session_connect(t_socket *new_socket);

/*
** private
*/

typedef char	*(*t_f_conv)(va_list *);

typedef struct	s_fun_map_conv
{
  int		type;
  t_f_conv	function;
}		t_fun_map_conv;

t_session       *session_get_session(void);
char		*session_get_mask_in(char *instruct);
char		*session_get_mask_out(int instruct);
t_se_execute_cb	session_get_callback(char *instruct);
char		*session_conv_arg_to_str(va_list *ap, int type);
char		*session_conv_int(va_list *ap);
char		*session_conv_str(va_list *ap);
t_instruction_in *session_retrieve_command(char *command); /*a changer pour l autre version*/

#endif	/*	SESSION_H_	*/
