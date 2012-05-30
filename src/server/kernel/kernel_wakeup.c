
#include "kernel.h"
#include "clock.h"

extern t_kernel *g_kernel;

bool kernel_register_wakeup(int time, kn_wakeup_cb callback, void* param)
{
  t_kernel_callback *wakeup;

  if (!(wakeup = malloc(sizeof(t_kernel_callback))))
    return false;
  clock_move_date(&wakeup->time, time);
  wakeup->callback = callback;
  wakeup->param = param;
  list_add_to(&g_kernel->callbacks, (fcmp) &kernel_wakeup_insert, wakeup);
  return true;
}

int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second)
{
  return clock_compare(&first->time, &second->time);
}

int kernel_wakeup()
{
  t_kernel_callback *wakeup;
  struct timeval *time;
  int count;

  count = 0;
  wakeup = list_get_begin(&g_kernel->callbacks);
  time = clock_get_time();
  while (wakeup)
    {
      if (clock_compare(time, &wakeup->time) <= 0)
	{
	  (*wakeup->callback)(wakeup->param);
	  free(wakeup);
	  list_pop_begin(&g_kernel->callbacks);
	  count++;
	}
      else
	return count;
      wakeup = list_get_begin(&g_kernel->callbacks);
    }
  return count;
}
