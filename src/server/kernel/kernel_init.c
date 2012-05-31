/*
** kernel_init.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Thu May 31 17:13:33 2012 quentin duval
*/

#include	"kernel.h"
#include "client.h"
#include "session.h"
#include "game.h"
#include "clock.h"

extern t_kernel *g_kernel;

bool kernel_session_init(t_socket *listener, int port)
{
  if (kernel_is_init(KN_SV_SESSION))
    {
      if (session_init(listener, port))
	{
	  g_kernel->init = g_kernel->init | KN_SV_SESSION;
	  return(true);
	}
    }
  return(false);
}

bool kernel_client_init()
{
  if (kernel_is_init(KN_SV_CLIENT))
    {
      client_manager_init();
      g_kernel->init = g_kernel->init | KN_SV_CLIENT;
      return true;
    }
  return false;
}

bool kernel_game_init(int x, int y, int nb_per_team)
{
  if (kernel_is_init(KN_SV_GAME))
    {
      if (game_init(x, y, nb_per_team))
	{
	  g_kernel->init = g_kernel->init | KN_SV_GAME;
	  return true;
	}
    }
  return(false);
}

bool kernel_clock_init(int frequence)
{
  if (kernel_is_init(KN_SV_CLOCK))
    {
      client_manager_init(frequence);
      g_kernel->init = g_kernel->init | KN_SV_CLOCK;
      return true;
    }
  return false;
 }

bool kernel_is_init(int service)
{
  return(g_kernel && g_kernel->init & service);
}
