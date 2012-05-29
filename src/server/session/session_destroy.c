/*
** session_destroy.c for zappy in /home/kersuz_v//Zappy/src/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 04:31:02 2012 vincent kersuzan
** Last update Tue May 29 04:36:53 2012 vincent kersuzan
*/

#include	<stdlib.h>

#include	"session.h"

int	session_destroy(void)
{
  t_session	*session;

  session = session_get_session();
  list_foreach(session->in, &free);
  list_clear(session->in);
  list_foreach(session->out, &free);
  list_clear(session->out);
  return (0);
}
