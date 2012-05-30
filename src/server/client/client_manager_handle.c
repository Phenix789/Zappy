
#include "client.h"

extern t_client_manager *g_client_manager;

void _client_manager_add(t_client *client)
{
  list_add_end(&g_client_manager->clients, client);
}

void _client_manager_remove(t_client *client)
{
  list_pop(&g_client_manager->clients, client);
}
