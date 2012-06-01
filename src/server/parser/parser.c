/*
** parser.c for parser in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 05:47:12 2012 vincent kersuzan
** Last update Thu May 31 17:15:36 2012 vincent kersuzan
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"parser.h"

static t_command	*parser_error_leaving(t_command *command,
					      void *buf1,
					      void *buf2,
					      char *err_mess)
{
  if (err_mess)
    perror(err_mess);
  if (command)
    parser_command_destroy(command);
  if (buf1)
    free(buf1);
  if (buf2)
    free(buf2);
  return (NULL);
}

static int	parser_set_type(int *type_int,
				char *mask, int *mask_index)
{
  char		*type_str;

  if ((*type_int = parser_find_elem_type(&mask[*mask_index])) < 0)
    return (-1);
  if ((type_str = parser_get_type_str(*type_int)))
    *mask_index += strlen(type_str);
  else
    return (-1);
  return (0);
}

static char	*parser_get_new_elem(char *mask, char *data,
				     int *mask_index, int *data_index)
{
  char		*elem;
  char		*split_str;

  if ((split_str = parser_find_key(&mask[*mask_index])))
    *mask_index += strlen(split_str);
  if ((elem = parser_extract_elem(&data[*data_index], false, split_str)))
    *data_index += strlen(elem);
  else
    return ((char *)parser_error_leaving(NULL, split_str, NULL, NULL));
  if (split_str)
    *data_index += strlen(split_str);
  free(split_str);
  return (elem);
}

t_command	*parser_parse(char *data, char *mask)
{
  int		type_int;
  char		*elem;
  int		mask_index;
  int		data_index;
  t_command	*command;

  mask_index = 0;
  data_index = 0;
  if (!data || !mask)
    return (NULL);
  if (!(command = parser_command_create(data)))
    return (NULL);
  while (data[data_index] && mask[mask_index])
    {
      if (parser_set_type(&type_int, mask, &mask_index) < 0)
	return (parser_error_leaving(command, NULL, NULL, NULL));
      if (!(elem = parser_get_new_elem(mask, data, &mask_index, &data_index)))
	return (parser_error_leaving(command, NULL, NULL, NULL));
      if (parser_save_data(command, elem, type_int) < 0)
	return (parser_error_leaving(command, elem, NULL, NULL));
      free(elem);
    }
  if (data[data_index] || mask[mask_index])
    return (parser_error_leaving(command, NULL, NULL, NULL));
  return (command);
}
