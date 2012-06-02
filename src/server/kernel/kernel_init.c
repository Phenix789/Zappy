/*
** kernel_init.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include "client.h"
#include "kernel.h"
#include "clock.h"
#include "logger.h"

extern t_kernel *g_kernel;

#define KN_CLIENT_MSG "[KERNEL] Kernel client init on port : %i"
bool kernel_client_init(t_socket *listener, int port)
{
  if (!kernel_is_init(KN_SV_CLIENT))
    {
      logger_message(KN_CLIENT_MSG, port);
      if (client_manager_init(listener, port))
	{
	  g_kernel->init = g_kernel->init | KN_SV_CLIENT;
	  return true;
	}
    }
  logger_error("[KERNEL] Kernel client error!!");
  return false;
}

#define KN_GAME_MSG "[Kernel] Kernel game init with %i:%i and %i connection(s)"
bool kernel_game_init(int x, int y, int nb_per_team)
{
  if (!kernel_is_init(KN_SV_GAME))
    {
      logger_message(KN_GAME_MSG, x, y, nb_per_team);
      if (game_init(x, y, nb_per_team))
	{
	  g_kernel->init = g_kernel->init | KN_SV_GAME;
	  return true;
	}
    }
  logger_error("[KERNEL] Kernel game error!!");
  return(false);
}

#define KN_CLOCK_MSG "[KERNEL] Kernel clock init with frequency at %i"
bool kernel_clock_init(int frequence)
{
  if (!kernel_is_init(KN_SV_CLOCK))
    {
      logger_message(KN_CLOCK_MSG, frequence);
      clock_init();
      clock_set_frequency(frequence);
      g_kernel->init = g_kernel->init | KN_SV_CLOCK;
      return true;
    }
  logger_error("[KERNEL] Kernel clock error!!");
  return false;
}

bool kernel_is_init(int service)
{
  return(g_kernel && g_kernel->init & service);
}
