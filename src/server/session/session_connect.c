/*
** session_connect.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/session
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 18:36:18 2012 quentin duval
** Last update Thu May 31 18:39:10 2012 quentin duval
*/

#include "session.h"
#include "client.h"
#include "logger.h"

void		session_connect(t_socket *new_sock)
{
  t_client	*client;

  logger_message("[SESSION] New client connected");
  client = client_create(new_sock);
  network_add_socket(new_sock, (t_nt_read_cb) &session_treat_data, client);
  session_send(client, "BIENVENUE");
}
