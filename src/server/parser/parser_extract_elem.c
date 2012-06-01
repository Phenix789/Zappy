/*
** parser_extract_elem.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Wed May 30 19:03:59 2012 vincent kersuzan
** Last update Thu May 31 17:10:30 2012 vincent kersuzan
*/

#include	<stdlib.h>
#include	<string.h>

#include	"parser.h"

char		*parser_extract_elem(char *data, bool last_arg,
				     char *split_str)
{
  unsigned int  len;
  int		data_index;

  if (!data)
    return (NULL);
  if (last_arg == true || !split_str)
    return (strdup(data));
  data_index = 0;
  len = strlen(split_str);
  while (strncmp(&data[data_index], split_str, len) &&
         data[data_index + len])
    {
      data_index += 1;
    }
  if (!strncmp(&data[data_index], split_str, len))
    return (strndup(data, data_index));
  return (NULL);
}
