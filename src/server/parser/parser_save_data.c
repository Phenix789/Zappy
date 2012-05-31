/*
** parser_save_data.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Wed May 30 21:17:23 2012 vincent kersuzan
** Last update Thu May 31 01:43:48 2012 vincent kersuzan
*/

#include	<string.h>
#include	<stdlib.h>

#include	"parser.h"

int		parser_save_data(t_command *command, char *buffer,
				 int type)
{
  t_argument	*argument;

  printf("save data \n");
  if (!(command->instruction))
    {
      if (type != PARSER_STRING_VALUE)
	{
	  printf("instruction should be a string\n");
	  return (-1);
	}
      if (!(command->instruction = strdup(buffer)))
	return (-1);
    }
  else
    {
      if (!(argument = malloc(sizeof(*argument))))
	return (-1);
      if (parser_argument_setter(type, buffer, argument) < 0)
	{
	  free(argument);
	  return (-1);
	}
      list_add_end(&(command->arguments), argument);
    }
  return (0);
}
