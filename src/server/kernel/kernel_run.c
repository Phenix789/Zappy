
#include "kernel.h"

extern t_kernel g_kernel;

int kernel_run()
{
  t_kernel_callback *first;
  int count;

  g_kernel->run = true;
  while (g_kernel->run)
    {
      first = list_get_begin(&g_kernel->callbacks);
      if (first)
	count = network_listen(clock_get_timeout(first->begin, first->time));
      else
	count = network_listen(NULL);
      if (!count)
	kernel_wakeup();
    }
}

void kernel_stop()
{
  g_kernel->run = false;
}
