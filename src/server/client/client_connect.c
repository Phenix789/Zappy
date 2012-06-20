/*
** client_connect.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/client
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 18:36:18 2012 quentin duval
** Last update Thu May 31 18:39:10 2012 quentin duval
*/

#include <string.h>
#include "client.h"
#include "kernel.h"
#include "gui.h"

void		client_connect(t_socket *new_sock)
{
  t_client	*client;

  logger_message("[CLIENT] New client connected");
  client = client_create(new_sock);
  network_add_socket(new_sock, (t_nt_read_cb) &client_receive, client);
  client_send(client, "BIENVENUE");
}

void client_unconnect(t_client *client)
{
  kernel_unregister_wakeup(client);
  network_close_socket_async(client->socket);
  client->socket = NULL;
  client_destroy(client);
}
