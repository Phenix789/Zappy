
#include "session.h"

static char *g_command = NULL;
static int g_length = 0;

static int session_cmp(t_instruction_in *in)
{
  if (in->length > g_length)
    return -1;
  return strncmp(in->instruction, g_command, in->length);
}

t_instruction_in *session_retrieve_command(char *command)
{
  g_command = command;
  g_length = strlen(command);
  return list_get_to(&session_get_session()->in, (fpred) &session_cmp);
}
