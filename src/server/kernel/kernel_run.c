
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
      if (network_listen(clock_get_timeout(kernel_next_event())))
	kernel_wakeup();
    }
}

void kernel_stop()
{
  g_kernel->run = false;
}

struct timeval *kernel_next_event()
{
  t_kernel_callback *wakeup;

  wakeup = list_get_begin(&g_kernel->callbacks);
  if (wakeup)
    return &wakeup->time;
  return KN_TIMEOUT_NOEVENT;
}
