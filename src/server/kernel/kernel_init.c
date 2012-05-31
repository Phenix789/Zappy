
#include <stdbool.h>
#include "kernel.h"
#include "network.h"

extern t_kernel * g_kernel;

bool kernel_network_init(int port)
{
  if (kernel_is_init(KN_SV_NETWORK))
    {
      network_create();
      socket_init(&g_kernel->listener);
      //Check l'enregistrement correct du client
      network_listen_to(&g_kernel->listener, port, (t_nt_create_cb) &client_create);
      g_kernel->init = g_kernel->init | KN_SV_NETWORK;
      return true;
    }
  return false;
}

bool kernel_session_init()
{
  if (kernel_is_init(KN_SV_SESSION))
    {
      g_kernel->init = g_kernel->init | KN_SV_SESSION;
      return true;
    }
  return false;
}

bool kernel_game_init(int x, int y, int time, int nb_per_team)
{
  (void) x;
  (void) y;
  (void) time;
  (void) nb_per_team;
  if (kernel_is_init(KN_SV_GAME))
    {
/*
      if (game_create(x, y, time, nb_per_team) == true)
	{
	  g_kernel->init = g_kernel->init | KN_SV_GAME;
	  return true;
	}
*/
    }
  return false;
}

bool kernel_add_team(char *team)
{
  (void) team;
/*
  if (kernel_is_init(KN_SV_GAME))
    return game_add_team(team);
*/
  return false;
}

bool kernel_is_init(int service)
{
  return g_kernel && g_kernel->init & service;
}
