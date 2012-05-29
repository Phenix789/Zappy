/*
** parser_count_arguments.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 10:33:53 2012 vincent kersuzan
** Last update Tue May 29 11:16:57 2012 vincent kersuzan
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
      if (!strncmp(&(mask[i]), PARSER_STRING_INDICATOR,
		   strlen(PARSER_STRING_INDICATOR)))
	{
	  i += strlen(PARSER_STRING_INDICATOR);
	  count++;
	}
      else if (!strncmp(&(mask[i]), PARSER_INT_INDICATOR,
		   strlen(PARSER_INT_INDICATOR)))
	{
	  i += strlen(PARSER_INT_INDICATOR);
	  count++;
	}
      else
	return (-1);
    }
  return (count);
}
