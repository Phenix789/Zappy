
#include "kernel.h"
#include "logger.h"

extern t_kernel *g_kernel;

void kernel_run()
{
  t_kernel_callback *first;
  int count;

  if (!kernel_is_init(KN_SV_INIT))
    {
      logger_warning("[run] Kernel is not initialised");
      return;
    }
  g_kernel->run = true;
  logger_message("[run] Kernel start");
  while (g_kernel->run)
    {
      first = list_get_begin(&g_kernel->callbacks);
      if (first)
	count = network_listen(clock_get_timeout(&first->begin, first->time));
      else
	count = network_listen(NULL);
      if (!count)
	kernel_wakeup();
    }
  logger_message("[run] Kernel stop");
}

void kernel_stop()
{
  g_kernel->run = false;
}
