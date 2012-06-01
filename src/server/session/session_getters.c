/*
** session_getters.c for zappy in /home/kersuz_v//zappy-2015-2014s-duval_q/src/server/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Thu May 31 18:13:28 2012 vincent kersuzan
** Last update Thu May 31 18:40:01 2012 vincent kersuzan
*/

#include	"session.h"

static t_instruction_in	*session_get_instruction_in(char *instruct)
{
  t_session		*session;
  t_instruction_in	*instruction_in;
  int			i;

  session = session_get_session();
  i = 0;
  while (i < list_size(&session->in))
    {
      instruction_in = list_get_at(&session->in, i);
      if (!(strcmp(instruction_in->instruction, instruct)))
	return (instruction_in);
      i++;
    }
  return (NULL);
}

static t_instruction_out	*session_get_instruction_out(int instruct)
{
  t_session			*session;
  t_instruction_out		*instruction_out;
  int				i;

  session = session_get_session();
  i = 0;
  while (i < list_size(&session->out))
    {
      instruction_out = list_get_at(&session->out, i);
      if (instruction_out->instruction == instruct)
        return (instruction_out);
      i++;
    }
  return (NULL);
}

char			*session_get_mask_in(char *instruct)
{
  t_instruction_in	*instruction_in;

  if (!(instruction_in = session_get_instruction_in(instruct)))
    return (NULL);
  return (instruction_in->mask);
}

t_se_execute_cb		session_get_callback(char *instruct)
{
  t_instruction_in	*instruction_in;

  if (!(instruction_in = session_get_instruction_in(instruct)))
    return (NULL);
  return (instruction_in->cb);
}

char			*session_get_mask_out(int instruct)
{
  t_instruction_out	*instruction_out;

  if (!(instruction_out = session_get_instruction_out(instruct)))
    return (NULL);
  return (instruction_out->mask);
}
