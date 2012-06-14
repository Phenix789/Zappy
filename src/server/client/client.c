
#include "client.h"
#include "network.h"
#include "session.h"

t_client *client_create(t_socket *socket)
{
  t_client *client;

  if (!(client = malloc(sizeof(t_client))))
    return NULL;
  return client_init(client, socket);
}

t_client *client_init(t_client *client, t_socket *socket)
{
  client->socket = socket;
  client->player = NULL;
  client->busy = false;
  list_init(&client->actions);
  _client_manager_add(client);
  return client;
}

void client_destroy(t_client *client)
{
  list_free(&client->actions);
  _client_manager_remove(client);
  if (client->player)
    game_add_free_player(client->player);
  if (client->socket)
    {
      socket_close(client->socket);
      network_del_socket(client->socket);
    }
  free(client);
}
