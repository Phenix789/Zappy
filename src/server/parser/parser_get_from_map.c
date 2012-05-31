/*
** parser_get_from_map.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Thu May 31 01:49:37 2012 vincent kersuzan
** Last update Thu May 31 01:50:11 2012 vincent kersuzan
*/

#include	"parser.h"

char            *parser_get_type_str(int type_int)
{
  t_known_type  *known_type;

  if (!(known_type = parser_find_known_type_from_int(type_int)))
    return (NULL);
  return (known_type->type_str);
}

int             parser_get_type_int(char *type_str)
{
  t_known_type  *known_type;

  if (!(known_type = parser_find_known_type_from_str(type_str)))
    return (-1);
  return (known_type->type_int);
}

t_f_arg_set     parser_get_argument_setter_int(int type_int)
{
  t_known_type  *known_type;

  if (!(known_type = parser_find_known_type_from_int(type_int)))
    return (NULL);
  return (known_type->argument_setter);
}

t_f_arg_set     parser_get_argument_setter_str(char *type_str)
{
  t_known_type  *known_type;

  if (!(known_type = parser_find_known_type_from_str(type_str)))
    return (NULL);
  return (known_type->argument_setter);
}
