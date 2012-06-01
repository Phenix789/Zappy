/*
** parser_find_key.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Wed May 30 18:33:51 2012 vincent kersuzan
** Last update Thu May 31 01:45:48 2012 vincent kersuzan
*/

#include	<string.h>

#include	"parser.h"

char		*parser_find_key(char *mask)
{
  int           i;
  int           mask_index;
  int		type;

  i = 0;
  mask_index = 0;
  while ((type = parser_find_elem_type(&mask[mask_index]) < 0) &&
	 mask[mask_index])
    {
      mask_index++;
    }
  if (!mask[mask_index] || mask_index == 0)
    return (NULL);
  return (strndup(mask, mask_index));
}
