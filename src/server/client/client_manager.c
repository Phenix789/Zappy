
#include "client.h"

t_client_manager *g_client_manager = NULL;

void client_manager_init()
{
  if (!(g_client_manager = malloc(sizeof(t_client_manager))))
    return;
  list_init(&g_client_manager->clients);
}

void client_manager_destroy()
{
  t_client *client;

  while ((client = list_get_begin(&g_client_manager->clients)))
    client_destroy(client);
  free(g_client_manager);
}

int client_manager_count()
{
  return list_size(&g_client_manager->clients);
}
