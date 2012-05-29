/*
** session_create.c for zappy in /home/kersuz_v//Zappy/src/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 04:07:25 2012 vincent kersuzan
** Last update Tue May 29 05:07:07 2012 vincent kersuzan
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"session.h"

int		session_create(void)
{
  t_session	*session;

  session = session_get_session();
  list_init(&(session->in));
  list_init(&(session->out));
  return (0);
}
