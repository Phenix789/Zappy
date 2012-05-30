
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
  _client_manager_add(client);
  network_add_socket(socket, &session_treat_data, client);
  return client;
}

t_client *client_destroy(t_client *client)
{
  _client_manager_remove(client);
  network_del_socket(client->socket);
  socket_close(client->socket);
}
