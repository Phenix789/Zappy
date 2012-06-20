
#include "client.h"
#include "network.h"

bool client_player_search(t_client *client, char *team)
{
  t_player *player;

  if (strcmp(team, "GRAPHIC") == 0)
    {
      gui_connect(client);
      return true;
    }
  else
    {
      logger_verbose("[CLIENT] Search player in team '%s'", team);
      player = game_get_slot(team);
      if (player)
	{
	  logger_verbose("[CLIENT] Find player %i for client", player->id);
	  client->player = player;
	  client_consume_food(client, KN_ERROR_OK);
	  client_send(client, "%i", player->team->free_slots);
	  client_send(client, "%i %i", game_width(), game_height());
	  client->exec = (t_execute_cb) &client_action_save;
	  return true;
	}
    }
  logger_error("[CLIENT] Any player find");
  return false;
}
