
#include "client.h"

t_client_manager *g_client_manager = NULL;

bool client_manager_init(int port)
{
  logger_message("[CLIENT] Manager starting ...");
  if (!(g_client_manager = malloc(sizeof(t_client_manager))))
    return false;
  list_init(&g_client_manager->clients);
  list_init(&g_client_manager->commands);
  if (!network_init()
      || !socket_init(&g_client_manager->listen)
      || !network_listen_to(&g_client_manager->listen, port, &client_connect))
    return false;
  logger_message("[CLIENT] Manager started");
  return true;
}

void client_manager_destroy()
{
  if (!g_client_manager)
    return;
  logger_message("[CLIENT] Manager destroy");
  list_foreach(&g_client_manager->clients, (feach) &client_destroy);
  list_clear(&g_client_manager->clients);
  list_free(&g_client_manager->commands);
  network_destroy();
  free(g_client_manager);
}

int client_manager_count()
{
  return list_size(&g_client_manager->clients);
}
