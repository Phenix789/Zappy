/*
** parser.h for zappy in /home/kersuz_v//Zappy/includes
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 02:26:28 2012 vincent kersuzan
** Last update Thu May 31 01:24:04 2012 vincent kersuzan
*/

#ifndef		PARSER_H_
# define	PARSER_H_

# include	<stdio.h>
# include	<stdbool.h>

# include	"list.h"

# define	PARSER_STRING_INDICATOR	"%s"
# define	PARSER_STRING_VALUE	1
# define	PARSER_INT_INDICATOR	"%d"
# define	PARSER_INT_VALUE	2
# define	PARSER_BUFFER_SIZE	512
# define	PARSER_NUM		"0123456789"
# define	DEFAULT_SPLIT_CHARS	" "

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

typedef int (*t_f_arg_set)(int, char *, t_argument *);

typedef struct	s_known_type
{
  char		*type_str;
  int		type_int;
  t_f_arg_set	argument_setter;
}		t_known_type;

/*
** interface utilisation
*/

t_command	*parser_parse(char *data, char *mask);
int		parser_get_int(t_command *command, unsigned int index);
char		*parser_get_string(t_command *command, unsigned int index);
void		parser_command_destroy(t_command *command);
bool		parser_is_match(char *data, char *mask);/**/
int		parser_count_arguments(char *mask);
bool		parser_str_check_contain(char *str, char *authorized);

/*
** fonctions a vocation interne
*/

//map
t_known_type    *parser_find_known_type_from_str(char *type_int);
t_known_type    *parser_find_known_type_from_int(int type_int);
char		*parser_get_type_str(int type_int);
int		parser_get_type_int(char *type_str);
int		parser_find_elem_type(char *mask);
t_f_arg_set	parser_get_argument_setter_int(int type_int);
t_f_arg_set	parser_get_argument_setter_str(char *str);

int		parser_argument_setter(int type, char *buffer,
                                       t_argument *argument);
int		parser_argument_setter_int(int type, char *buffer,
                                   t_argument *argument);
int		parser_argument_setter_str(int type, char *buffer,
                                   t_argument *argument);
int		parser_save_data(t_command *command, char *buffer,
				 int type);

char            *parser_find_key(char *mask); //retourne le split_str
char		*parser_extract_elem(char *data, bool last_arg,
				     char *split_str);
t_command	*parser_command_create(char *original_str);

#endif	/*	PARSER_H_	*/
