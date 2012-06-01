/*
** session_register_in.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:03:55 2012 vincent kersuzan
** Last update Tue May 29 05:06:15 2012 vincent kersuzan
*/

#include	"session.h"

int session_register_in(char *instruction,
			char *mask,
			t_se_execute_cb cb)
{
  t_session *session;
  t_instruction_in *instruction_in;

  session = session_get_session();
  if (!(instruction_in = malloc(sizeof(*instruction_in))))
    return(-1);
  if ((instruction_in->instruction = strdup(instruction)) == NULL ||
      (instruction_in->mask = strdup(mask)) == NULL)
    return(-1);
  instruction_in->length = strlen(instruction_in->instruction);
  instruction_in->cb = cb;
  list_add_end(&(session->in), instruction_in);
  return(0);
}
