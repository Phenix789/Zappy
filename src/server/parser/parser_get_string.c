/*
** parser_get_string.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 09:31:02 2012 vincent kersuzan
** Last update Tue May 29 09:41:41 2012 vincent kersuzan
*/

#include        "parser.h"

char		*parser_get_string(t_command *command, unsigned int index)
{
  t_argument    *argument;
  int           i;
  unsigned int	count_string;

  i = 0;
  count_string = 0;
  while (i < list_size(&(command->arguments)))
    {
      argument = (t_argument *)list_get_at(&(command->arguments), i);
      if (argument->type == PARSER_STRING_VALUE)
        {
          if (count_string == index)
            return ((char *)argument->data);
          count_string++;
        }
      i++;
    }
  return (NULL);
}
