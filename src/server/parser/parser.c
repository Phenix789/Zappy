/*
** parser.c for parser in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 05:47:12 2012 vincent kersuzan
** Last update Tue May 29 11:49:57 2012 vincent kersuzan
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"parser.h"

static t_command	*parser_error_leaving(t_command *command,
					      char *buffer,
					      char *err_mess)
{
  if (err_mess)
    perror(err_mess);
  if (command)
    parser_command_destroy(command);
  if (buffer)
    free(buffer);
  return (NULL);
}

static int	parser_find_elem_type(char *mask, int *mask_index)
{
  if (!strncmp(&(mask[*mask_index]), PARSER_STRING_INDICATOR,
               strlen(PARSER_STRING_INDICATOR)))
    {
      *mask_index += strlen(PARSER_STRING_INDICATOR);
      return (PARSER_STRING_VALUE);
    }
  else if (!strncmp(&(mask[*mask_index]), PARSER_INT_INDICATOR,
                    strlen(PARSER_INT_INDICATOR)))
    {
      *mask_index += strlen(PARSER_INT_INDICATOR);
      return (PARSER_INT_VALUE);
    }
  else
    return (0);
}

static int	parser_extract_elem(char *data, int *data_index,
				    char *buffer, bool last_arg)
{
  while (data[*data_index] == ' ')
    {
      *data_index += 1;
    }
  if (last_arg == true)
    strncpy(buffer, &(data[*data_index]), PARSER_BUFFER_SIZE);
  else
    if (!(sscanf(&(data[*data_index]), PARSER_STRING_INDICATOR, buffer)))
      return (-1);
  *data_index += strlen(buffer);
  return (0);
}

static t_command	*parser_gen_command(char *original_str)
{
  t_command		*command;

  if (!(command = malloc(sizeof(*command))))
    {
      perror("malloc");
      return (NULL);
    }
  command->instruction = NULL;
  if (!(command->original_str = strdup(original_str)))
    {
      perror("malloc");
      free(command);
      return (NULL);
    }
  list_init(&(command->arguments));
  return (command);
}

static t_argument	*parser_gen_argument(int type, char *buffer)
{
  t_argument		*argument;

  if (!(argument = malloc(sizeof(*argument))))
    return ((t_argument *)parser_error_leaving(NULL, NULL, "malloc"));
  if (type == PARSER_STRING_VALUE)
    {
      argument->type = type;
      if (!(argument->data = strdup(buffer)))
	return ((t_argument *)parser_error_leaving(NULL, (char *)argument,
						   "strdup"));
    }
  else if (type == PARSER_INT_VALUE)
    {
      argument->type = type;
      if (!(argument->data = malloc(sizeof(int))))
	return ((t_argument *)parser_error_leaving(NULL, (char *)argument,
						   "malloc"));
      *((int *)argument->data) = atoi(buffer);
      if (parser_str_check_contain(buffer, PARSER_NUM) == false)
	{
	  free(argument->data);
	  free(argument);
	  return (NULL);
	}
    }
  return (argument);
}

static int	parser_data_save(t_command *command, char *buffer, int type)
{
  t_argument	*argument;

  if (!(command->instruction))
    {
      if (!(command->instruction = strdup(buffer)))
	{
	  perror("strdup");
	  return (-1);
	}
    }
  else
    {
      if (!(argument = parser_gen_argument(type, buffer)))
	return (-1);
      list_add_end(&(command->arguments), argument);
    }
  return (0);
}

t_command	*parser_parse(char *data, char *mask)
{
  char		*buffer;
  int		data_index;
  int		mask_index;
  int		type;
  t_command	*command;
  int		nb_arguments;
  bool		last_arg;

  if (!(command = parser_gen_command(data)))
    return (NULL);
  if ((nb_arguments = parser_count_arguments(mask)) <= 0)
    return (NULL);
  data_index = 0;
  mask_index = 0;
  type = 1;
  if (!(buffer = malloc(sizeof(*buffer) * PARSER_BUFFER_SIZE)))
    return (parser_error_leaving(NULL, NULL, "malloc"));
  while (type > 0)
    {
      if ((type = parser_find_elem_type(mask, &mask_index)) > 0)
	{
	  if (list_size(&(command->arguments)) + 1 == nb_arguments - 1 &&
	      command->instruction)
	    last_arg = true;
	  else
	    last_arg = false;
	  if ((parser_extract_elem(data, &data_index,
				   buffer, last_arg)) < 0)
	    return (parser_error_leaving(command, buffer, NULL));
	  if (parser_data_save(command, buffer, type) < 0)
	    return (parser_error_leaving(command, buffer, NULL));
	}
    }
  free(buffer);
  return (command);
}
