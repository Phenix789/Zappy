/*
** session_retrieve.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:05:48 2012 vincent kersuzan
** Last update Tue May 29 05:06:35 2012 vincent kersuzan
*/

#include "session.h"

static char *g_command = NULL;
static int g_length = 0;

static int session_cmp(t_instruction_in *in)
{
  if (in->length < g_length)
    if (strncmp(in->instruction, g_command, in->length) == 0)
      return 0;
  return -1;
}

t_instruction_in *session_retrieve_command(char *command)
{
  g_command = command;
  g_length = strlen(command);
  return list_get_to(&session_get_session()->in, (fpred) & session_cmp);
}
