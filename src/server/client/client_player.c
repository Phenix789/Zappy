
#include "client.h"

bool client_player_search(t_client *client, char *team)
{
  t_player *player;

  player = game_get_slot(team);
  if (player)
    {
      client->player = player;
      client_consume_food(client);
      client_send(client, "%i", player->team->free_slots);
      client_send(client, "%i %i", game_width(), game_height());
      return true;
    }
  return false;
}
