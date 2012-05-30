
#include "client.h"

int client_count_action(t_client *client)
{
  return list_size(&client->actions);
}

t_command *client_next_action(t_client *client)
{
  t_command *command;

  command = list_get_begin(&client->actions);
  list_pop_begin(&client->actions);
  return command;
}

bool client_save_action(t_client *client, t_command *command)
{
  if (list_size(&client->actions) >= CLIENT_MAX_ACTIONS)
    return false;
  list_add_end(&client->actions, command);
  return true;
}
