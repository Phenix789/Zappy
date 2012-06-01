/*
** session_destroy.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:31:02 2012 vincent kersuzan
** Last update Tue May 29 05:28:59 2012 vincent kersuzan
*/

#include	<stdlib.h>

#include	"session.h"
#include "logger.h"

static void		delete_instruction_in(void *data)
{
  t_instruction_in	*instruction_in;

  instruction_in = (t_instruction_in *)data;
  free(instruction_in->instruction);
  free(instruction_in->mask);
  free(instruction_in);
}

static void		delete_instruction_out(void *data)
{
  t_instruction_out	*instruction_out;

  instruction_out = (t_instruction_out *)data;
  free(instruction_out->mask);
  free(instruction_out);
}

int		session_destroy(void)
{
  t_session	*session;

  logger_message("[SESSION] Stop session service");
  session = session_get_session();
  list_foreach(&(session->in), &delete_instruction_in);
  list_clear(&(session->in));
  list_foreach(&(session->out), &delete_instruction_out);
  list_clear(&(session->out));
  return (0);
}
