/*
** session_create.c for zappy in /home/kersuz_v//Zappy/src/session
**
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
**
** Started on  Tue May 29 04:07:25 2012 vincent kersuzan
** Last update Thu May 31 22:01:08 2012 quentin duval
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>

#include	"session.h"
#include	"network.h"
#include	"logger.h"

bool		session_init(t_socket *listen, int port)
{
  logger_message("[SESSION] starting session service");
  if (session_create() == false
      || network_init() == false
      || network_listen_to(listen, port, &session_connect) == false)
    return (false);
  logger_message("[SESSION] service started");
  return (true);
}

bool		session_create(void)
{
  t_session	*session;

  session = session_get_session();
  list_init(&(session->in));
  list_init(&(session->out));
  return (true);
}
