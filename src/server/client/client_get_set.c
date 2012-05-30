
#include "client.h"

t_socket *client_get_socket(t_client *client)
{
  return client->socket;
}

t_player *client_get_player(t_client *client)
{
  return client->player;
}

bool client_set_player(t_client *client, t_player *player)
{
  if (client->player)
    return false;
  client->player = player;
  return true;
}
