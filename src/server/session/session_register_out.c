/*
** session_register_out.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:05:48 2012 vincent kersuzan
** Last update Tue May 29 05:06:35 2012 vincent kersuzan
*/

#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>

#include	"session.h"

int session_register_out(int instruction, char *mask)
{
  t_session *session;
  t_instruction_out *instruction_out;

  session = session_get_session();
  if (!(instruction_out = malloc(sizeof(*instruction_out))))
    return(-1);
  if (!(instruction_out->mask = strdup(mask)))
    return(-1);
  instruction_out->instruction = instruction;
  list_add_end(&(session->out), instruction_out);
  return(0);
}
