/*
** kernel_run.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include "kernel.h"
#include "logger.h"

extern t_kernel *g_kernel;

void kernel_run()
{
  t_kernel_callback *first;
  struct timeval *timeout;
  int count;

  if (!kernel_is_init(KN_SV_INIT))
    {
      logger_warning("[KERNEL] Kernel is not initialised");
      return;
    }
  g_kernel->run = true;
  logger_message("[KERNEL] Kernel start");
  while (g_kernel->run)
    {
      timeout = NULL;
      first = list_get_begin(&g_kernel->callbacks);
      if (first)
	timeout = clock_get_timeout(&first->begin, first->time);
      count = network_listen(timeout);
      if (!count)
	kernel_wakeup();
    }
  logger_message("[KERNEL] Kernel stop");
}

void kernel_stop()
{
  g_kernel->run = false;
}
