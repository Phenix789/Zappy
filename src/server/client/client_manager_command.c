
#include <string.h>
#include "client.h"

extern t_client_manager *g_client_manager;

static t_command_callback *_clm_command_create(char *instruction, char *mask, t_execute_cb callback)
{
  t_command_callback *command;

  if (!(command = malloc(sizeof(t_command_callback))))
    return NULL;
  memset(command, 0, sizeof(t_execute_cb));
  strncpy(command->instruction, instruction, CLM_CB_SIZE);
  strncpy(command->mask, mask, CLM_CB_SIZE);
  command->length = strlen(instruction);
  command->callback = callback;
  return command;
}

static int _clm_command_retrieve_cmp(t_command_callback *command, char *action)
{
  return strncmp(command->instruction, action, command->length);
}

void clm_command_register(char *instruction, char *mask, t_execute_cb callback)
{
  t_command_callback *command;

  command = _clm_command_create(instruction, mask, callback);
  if (command)
    list_add_end(&g_client_manager->commands, command);
}

t_command_callback *clm_command_retrieve(char *action)
{
  return list_get_to_param(&g_client_manager->commands, (fpredp) &_clm_command_retrieve_cmp, action);
}
