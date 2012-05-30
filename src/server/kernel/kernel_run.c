
#include "kernel.h"
#include "clock.h"
#include "network.h"
#include "game.h"

extern t_kernel g_kernel;

int kernel_run()
{
  g_kernel->run = true;
  while (g_kernel->run)
    {
      while (clock_turn_played())
	{
	  game_turn();
	  kernel_wakeup();
	  network_listen();
	  clock_turn_played();
	}
      clock_wait();
    }
}

void kernel_stop()
{
  g_kernel->run = false;
}
