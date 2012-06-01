/*
** session_send.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:02:23 2012 vincent kersuzan
** Last update Fri Jun  1 01:04:27 2012 vincent kersuzan
*/

#include	<stdio.h>
#include	<stdarg.h>

#include	"parser.h"
#include	"session.h"

static char	*add_data(char *buffer, char *data, int n)
{
  if (!buffer)
    return (strndup(data, n));
  if (!(buffer = realloc(buffer, strlen(buffer) + n + 1)))
    return (NULL);
  strncat(buffer, data, n);
  return (buffer);
}

static int	error_leaving(char *str1, char *str2, char *str3)
{
  free(str1);
  free(str2);
  free(str3);
  return (-1);
}

static int	save_arg_str(int type, va_list *ap, char **buffer)
{
  char		*argument;

  if (!(argument = session_conv_arg_to_str(ap, type)))
    {
      free(argument);
      return (-1);
    }
  if (!(*buffer = add_data(*buffer, argument, strlen(argument))))
    {
      free(argument);
      return (-1);
    }
  free(argument);
  return (0);
}

static int      save_mask_str(char *mask, int *type,
			      int *mask_index, char **buffer)
{
  int           i;
  int           type_int;
  char		*type_str;

  i = 0;
  while (mask[*mask_index + i]
         && ((type_int = parser_find_elem_type(&mask[*mask_index + i])) < 0))
    {
      i++;
    }
  if (type)
    *type = type_int;
  if (!(*buffer = add_data(*buffer, &mask[*mask_index], i)))
    return (-1);
  if (!(type_str = parser_get_type_str(*type)))
    return (-1);
  *mask_index += i + strlen(type_str);
  return (i);
}

int		session_send(t_client *client, char *mask, ...)
{
  va_list	ap;
  int		type;
  int		mask_index;
  char		*buffer;

  logger_verbose("[SESSION] Send data with mask '%s'", mask);
  (void)client;
  buffer = NULL;
  mask_index = 0;
  va_start(ap, mask);
  while (mask[mask_index])
    {
      if (save_mask_str(mask, &type, &mask_index, &buffer) < 0)
	return (error_leaving(buffer, NULL, NULL));
      if (save_arg_str(type, &ap, &buffer) < 0)
	return (error_leaving(buffer, NULL, NULL));
    }
  va_end(ap);
  free(buffer);
  return (0);
}
