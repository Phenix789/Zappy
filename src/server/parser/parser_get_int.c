/*
** parser_get_int.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 09:25:03 2012 vincent kersuzan
** Last update Tue May 29 09:36:14 2012 vincent kersuzan
*/

#include	"parser.h"

int		parser_get_int(t_command *command, unsigned int index)
{
  t_argument	*argument;
  int		i;
  unsigned int	count_int;

  i = 0;
  count_int = 0;
  while (i < list_size(&(command->arguments)))
    {
      argument = (t_argument *)list_get_at(&(command->arguments), i);
      if (argument->type == PARSER_INT_VALUE)
	{
	  if (count_int == index)
	    return (*((int *)argument->data));
	  count_int++;
	}
      i++;
    }
  return (-1);
}
