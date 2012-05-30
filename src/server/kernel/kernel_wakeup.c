
#include "kernel.h"
#include "clock.h"

extern t_kernel *g_kernel;

bool kernel_register_wakeup(int nb_turn, kn_wakeup_cb callback, void* param)
{
  t_kernel_callback *wakeup;

  if (!(wakeup = malloc(sizeof(t_kernel_callback))))
    return false;
  wakeup->turn = clock_turn() + nb_turn;
  wakeup->callback = callback;
  wakeup->param = param;
  list_add_to(&g_kernel->callbacks, (fcmp) &kernel_wakeup_insert, wakeup);
  return true;
}

int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second)
{
  return second->turn - first->turn;
}

int kernel_wakeup()
{
  t_kernel_callback *wakeup;
  int count;
  unsigned long turn;

  count = 0;
  turn = clock_turn();
  wakeup = list_get_begin(&g_kernel->callbacks);
  while (wakeup)
    {
      if (wakeup->turn <= turn)
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
