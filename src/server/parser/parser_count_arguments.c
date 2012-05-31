/*
** parser_count_arguments.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 10:33:53 2012 vincent kersuzan
** Last update Thu May 31 01:22:16 2012 vincent kersuzan
*/

#include	<stdio.h>
#include	<string.h>

#include	"parser.h"

int	parser_count_arguments(char *mask)
{
  int	count;
  int	i;

  i = 0;
  count = 0;
  while (mask[i])
    {
      if (parser_find_elem_type(&mask[i]) > 0)
	count++;
      i++;
    }
  return (count);
}
