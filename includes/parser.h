/*
** parser.h for zappy in /home/kersuz_v//Zappy/includes
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 02:26:28 2012 vincent kersuzan
** Last update Tue May 29 11:07:14 2012 vincent kersuzan
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<stdbool.h>

# include	"list.h"

# define	PARSER_STRING_INDICATOR	"%s"
# define	PARSER_STRING_VALUE	1
# define	PARSER_INT_INDICATOR	"%d"
# define	PARSER_INT_VALUE	2
# define	PARSER_BUFFER_SIZE	512
# define	PARSER_NUM		"0123456789"

/*
static const char	*parser_string_indicator = "%s";
static const int	parser_string_value = 1;
static const char	*parser_int_indicator = "%d";
static const int	parser_int_value = 2;
static const int	parser_buffer_size = 512;
*/

typedef struct	s_argument
{
  int		type;
  void		*data;
}		t_argument;

typedef struct	s_command
{
  char		*instruction;
  t_list	arguments;
  char		*original_str;
}		t_command;

t_command	*parser_parse(char *data, char *mask);
int		parser_get_int(t_command *command, unsigned int index);
char		*parser_get_string(t_command *command, unsigned int index);
void		parser_command_destroy(t_command *command);
bool		parser_is_match(char *data, char *mask);
int		parser_count_arguments(char *mask);
bool		parser_str_check_contain(char *str, char *authorized);

#endif	/*	PARSER_H_	*/
