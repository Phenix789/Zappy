/*
** parser_argument_setter.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Wed May 30 20:30:59 2012 vincent kersuzan
** Last update Thu May 31 01:33:28 2012 vincent kersuzan
*/

#include	<string.h>

#include	"parser.h"

int	parser_argument_setter_str(int type, char *buffer,
				   t_argument *argument)
{
  char	*tmp;

  argument->type = type;
  if (!buffer)
    return (-1);
  if (!(tmp = strdup(buffer)))
    return (-1);
  argument->data = (void *)tmp;
  return (0);
}

int	parser_argument_setter_int(int type, char *buffer,
                                   t_argument *argument)
{
  argument->type = type;
  if (!(argument->data = malloc(sizeof(int))))
    {
      perror("malloc");
      return (-1);
    }
  *(int *)argument->data = atoi(buffer);
  if (parser_str_check_contain(buffer, PARSER_NUM) == false)
    return (-1);
  return (0);
}

int		parser_argument_setter(int type, char *buffer,
				       t_argument *argument)
{
  t_f_arg_set	argument_setter;

  printf("argument setter\n");
  if ((argument_setter = parser_get_argument_setter_int(type)))
    return (argument_setter(type, buffer, argument));
  return (-1);
}
