/*
** parser_save_data.c for zappy in /home/kersuz_v//Zappy/src/server/parser
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Wed May 30 21:17:23 2012 vincent kersuzan
** Last update Thu May 31 17:28:11 2012 vincent kersuzan
*/

#include	<string.h>
#include	<stdlib.h>

#include	"parser.h"
#include "logger.h"

static int	error_leaving_int(void *buf1, void *buf2,
				  char *errno_msg, char *error_msg)
{
  if (buf1)
    free(buf1);
  if (buf2)
    free(buf2);
  if (errno_msg)
    perror(errno_msg);
  if (error_msg)
    logger_error(error_msg);
  return (-1);
}

int		parser_save_data(t_command *command, char *buffer,
				 int type)
{
  t_argument	*argument;

  if (!(command->instruction))
    {
      if (type != PARSER_STRING_VALUE)
	return (error_leaving_int(NULL, NULL, NULL,
				  "instruction should be a string\n"));
      if (!(command->instruction = strdup(buffer)))
	return (error_leaving_int(NULL, NULL, "strdup", NULL));
    }
  else
    {
      if (!(argument = malloc(sizeof(*argument))))
	return (error_leaving_int(NULL, NULL, "malloc", NULL));
      if (parser_argument_setter(type, buffer, argument) < 0)
	return (error_leaving_int(argument, NULL, NULL, NULL));
      list_add_end(&(command->arguments), argument);
    }
  return (0);
}
