/*
** session_create.c for zappy in /home/kersuz_v//Zappy/src/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 04:07:25 2012 vincent kersuzan
** Last update Thu May 31 18:32:23 2012 quentin duval
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<stdbool.h>

#include	"session.h"
#include	"network.h"

int		session_init(int port, t_socket *listen)
{
  if (session_create() == false
      || network_init() == false
      || network_listen_to(port, listen, &session_connect) == false)
    return (false);
  return (true);
}

int		session_create(void)
{
  t_session	*session;

  session = session_get_session();
  list_init(&(session->in));
  list_init(&(session->out));
  return (0);
}
