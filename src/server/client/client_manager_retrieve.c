
#include "client.h"

extern t_client_manager *g_client_manager;

static void *cmp;

static int _client_manager_cmp_player(t_client *client)
{
  return client->player == cmp;
}

static int _client_manager_cmp_socket(t_client *client)
{
  return client->socket == cmp;
}

t_client *client_manager_retrieve_from_player(t_player* player)
{
  cmp = player;
  return list_get_to(&g_client_manager->clients, &_client_manager_cmp_player);
}

t_client *client_manager_retrieve_from_socket(t_socket* socket)
{
  cmp = socket;
  return list_get_to(&g_client_manager->clients, &_client_manager_cmp_socket);
}
