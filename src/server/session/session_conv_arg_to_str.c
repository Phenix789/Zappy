/*
** session_conv_arg_to_str.c for zappy in /home/kersuz_v//zappy-2015-2014s-duval_q/src/server/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Fri Jun  1 00:09:53 2012 vincent kersuzan
** Last update Fri Jun  1 00:27:15 2012 vincent kersuzan
*/

#include	"session.h"

static t_fun_map_conv	g_fun_map_conv[] =
  {
    {PARSER_STRING_VALUE, &session_conv_str},
    {PARSER_INT_VALUE, &session_conv_int},
    {-1, NULL}
  };

char	*session_conv_str(va_list *ap)
{
  char	*arg_str;

  arg_str = va_arg(*ap, char *);
  return (strdup(arg_str));
}

char	*session_conv_int(va_list *ap)
{
  int	arg_int;
  char	*ret;

  arg_int = va_arg(*ap, int);
  if (!(ret = malloc(sizeof(*ret) * 512)))
    return (NULL);
  sprintf(ret, "%d", arg_int);
  return (ret);
}

char	*session_conv_arg_to_str(va_list *ap, int type)
{
  int	i;

  i = 0;
  while (g_fun_map_conv[i].function)
    {
      if (g_fun_map_conv[i].type == type)
	return (g_fun_map_conv[i].function(ap));
      i++;
    }
  return (NULL);
}
