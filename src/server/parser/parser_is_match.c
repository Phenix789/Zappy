/*
** parser_is_match.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 10:22:44 2012 vincent kersuzan
** Last update Tue May 29 10:22:45 2012 vincent kersuzan
*/

#include	"parser.h"

bool		parser_is_match(char *data, char *mask)
{
  t_command	*command;

  command = parser_parse(data, mask);
  if (command)
    {
      parser_command_destroy(command);
      return (true);
    }
  return (false);
}
