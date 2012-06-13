
#include <string.h>
#include "client.h"

int client_action_count(t_client *client)
{
  return list_size(&client->actions);
}

bool client_action_save(t_client *client, char *action)
{
  if (!client->player)
    {
      logger_verbose("[CLIENT] Client search player");
      return client_player_search(client, action);
    }
  if (clm_command_retrieve(action))
    {
      if (!client->busy)
	{
	  client_execute(client, action);
	  client->busy = true;
	}
      else if (list_size(&client->actions) <= CLIENT_MAX_ACTIONS)
	{
	  logger_verbose("[CLIENT] Client %i save action '%s'", CLP_ID(client), action);
	  list_add_end(&client->actions, strdup(action));
	}
      else
	{
	  logger_warning("[CLIENT] Client %i action '%s' ignored", CLP_ID(client), action);
	  return false;
	}
      return true;
    }
  logger_warning("[CLIENT] Client %i try to save unknown command '%s'", CLP_ID(client), action);
  return false;
}

void client_action_finish(t_client *client)
{
  char *action;

  logger_verbose("[CLIENT] Client %i has finish action", CLP_ID(client));
  if (list_size(&client->actions))
    {
      logger_verbose("[CLIENT] Client %i have action in stack", CLP_ID(client));
      action = list_get_begin(&client->actions);
      list_pop_begin(&client->actions);
      client_execute(client, action);
      free(action);
    }
  else
    client->busy = false;
}

void client_execute(t_client *client, char *action)
{
  t_command_callback *command;

  command = clm_command_retrieve(action);
  if (command)
    {
      logger_verbose("[CLIENT] Client %i execute action '%s'", CLP_ID(client), action);
      (*command->callback)(client, action);
    }
}
