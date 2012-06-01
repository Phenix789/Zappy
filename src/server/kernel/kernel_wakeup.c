
#include "kernel.h"
#include "clock.h"
#include	"logger.h"

extern t_kernel *g_kernel;

bool kernel_register_wakeup(unsigned int time, kn_wakeup_cb callback, void* param)
{
  t_kernel_callback *wakeup;

  if (!(wakeup = malloc(sizeof(t_kernel_callback))))
    return false;
  clock_set_time_to_current(&wakeup->begin);
  wakeup->time = time;
  wakeup->callback = callback;
  wakeup->param = param;
  list_add_to(&g_kernel->callbacks, (fcmp) &kernel_wakeup_insert, wakeup);
  return true;
}

int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second)
{
  struct timeval first_end;
  struct timeval second_end;

  first_end = first->begin;
  clock_move_date(&first_end, first->time);
  second_end = second->begin;
  clock_move_date(&second_end, second->time);
  return clock_compare(&first_end, &second_end);
}

int kernel_wakeup()
{
  t_kernel_callback *wakeup;
  struct timeval begin;
  struct timeval *time;
  int count;

  count = 0;
  wakeup = list_get_begin(&g_kernel->callbacks);
  time = clock_get_time();
  while (wakeup)
    {
      begin = wakeup->begin;
      clock_move_date(&begin, wakeup->time);
      if (clock_compare(time, &begin) > 0)
	{
	  (*wakeup->callback)(wakeup->param, KN_ERROR_OK);
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
