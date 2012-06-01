/*
** kernel_init.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:52:16 2012 quentin duval
*/

#include	"kernel.h"
#include "client.h"
#include "session.h"
#include "game.h"
#include "clock.h"
#include "logger.h"

extern t_kernel *g_kernel;

bool kernel_session_init(t_socket *listener, int port)
{
  if (!kernel_is_init(KN_SV_SESSION))
    {
      logger_message("[KERNEL] Kernel session init on port : %i", port);
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
  if (!kernel_is_init(KN_SV_CLIENT))
    {
      logger_message("[KERNEL] Kernel client init");
      client_manager_init();
      g_kernel->init = g_kernel->init | KN_SV_CLIENT;
      return true;
    }
  return false;
}

bool kernel_game_init(int x, int y, int nb_per_team)
{
  if (!kernel_is_init(KN_SV_GAME))
    {
      logger_message("[KERNEL] Kernel game init with %i:%i and %i connection(s)", x, y, nb_per_team);
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
  if (!kernel_is_init(KN_SV_CLOCK))
    {
      logger_message("[KERNEL] Kernel clock init with frequency at %i", frequence);
      clock_init();
      clock_set_frequency(frequence);
      g_kernel->init = g_kernel->init | KN_SV_CLOCK;
      return true;
    }
  return false;
 }

bool kernel_is_init(int service)
{
  return(g_kernel && g_kernel->init & service);
}
