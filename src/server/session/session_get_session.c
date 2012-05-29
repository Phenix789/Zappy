/*
** session_get_session.c for zappy in /home/kersuz_v//Zappy/src/session
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 04:32:04 2012 vincent kersuzan
** Last update Tue May 29 04:32:51 2012 vincent kersuzan
*/

#include	"session.h"

t_session		*session_get_session(void)
{
  static t_session	session;

  return (&session);
}
