
#include "client.h"

t_client_manager *g_client_manager = NULL;

bool client_manager_init(t_socket *listen, int port)
{
  logger_message("[CLIENT] Manager starting ...");
  if (!(g_client_manager = malloc(sizeof(t_client_manager))))
    return false;
  list_init(&g_client_manager->clients);
  list_init(&g_client_manager->commands);
  if (!network_init() || !network_listen_to(listen, port, &client_connect))
    return false;
  logger_message("[CLIENT] Manager started");
  return true;
}

void client_manager_destroy()
{
  t_client *client;

  logger_message("[CLIENT] Manager stopped");
  while ((client = list_get_begin(&g_client_manager->clients)))
    client_destroy(client);
  free(g_client_manager);
}

int client_manager_count()
{
  return list_size(&g_client_manager->clients);
}
