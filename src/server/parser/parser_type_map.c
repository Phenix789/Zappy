/*
** parser_type_map.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Wed May 30 18:43:45 2012 vincent kersuzan
** Last update Thu May 31 01:50:19 2012 vincent kersuzan
*/

#include	<string.h>

#include	"parser.h"

static t_known_type	g_known_type[] =
  {
    {"%s", PARSER_STRING_VALUE, &parser_argument_setter_str},
    {"%d", PARSER_INT_VALUE, &parser_argument_setter_int},
    {NULL, -1, NULL}
  };

t_known_type	*parser_find_known_type_from_int(int type_int)
{
  int		i;

  i = 0;
  while (g_known_type[i].type_str)
    {
      if (type_int == g_known_type[i].type_int)
	return (&g_known_type[i]);
      i++;
    }
  return (NULL);
}

t_known_type    *parser_find_known_type_from_str(char *type_str)
{
  int		i;

  i = 0;
  while (g_known_type[i].type_str)
    {
      if (!(strcmp(type_str, g_known_type[i].type_str)))
        return (&g_known_type[i]);
      i++;
    }
  return (NULL);
}

int	parser_find_elem_type(char *mask)
{
  int	i;

  i = 0;
  while (g_known_type[i].type_str)
    {
      if (!(strncmp(mask, g_known_type[i].type_str,
		    strlen(g_known_type[i].type_str))))
	return (g_known_type[i].type_int);
      i++;
    }
  return (-1);
}
