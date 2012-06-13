/*
** kernel_wakeup.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include "kernel.h"
#include "clock.h"
#include "logger.h"

extern t_kernel *g_kernel;

bool kernel_register_wakeup(unsigned int time, kn_wakeup_cb callback, void* param)
{
  t_kernel_callback *wakeup;

  logger_debug("[KERNEL] Register wakeup for %i time, %i in standby", time, list_size(&g_kernel->callbacks));
  if (!(wakeup = malloc(sizeof(t_kernel_callback))))
    return false;
  clock_set_time_to_current(&wakeup->begin);
  wakeup->time = time;
  wakeup->callback = callback;
  wakeup->param = param;
  list_add_to(&g_kernel->callbacks, (fcmp) &kernel_wakeup_insert, wakeup);
  return true;
}

void kernel_unregister_wakeup(void *param)
{
  t_list_node *current;
  t_list_node *next;

  current = g_kernel->callbacks.head;
  while (current)
    {
      next = current->next;
      if (((t_kernel_callback *) current->data)->param == param)
	{
	  free(current->data);
	  _list_pop_node(&g_kernel->callbacks, current);
	}
      current = next;
    }
}

int kernel_wakeup_insert(t_kernel_callback *first, t_kernel_callback *second)
{
  struct timeval first_end;
  struct timeval second_end;

  first_end = first->begin;
  clock_move_date(&first_end, first->time);
  second_end = second->begin;
  clock_move_date(&second_end, second->time);
  logger_debug("[KERNEL] Insert %u : %u", first_end.tv_sec, second_end.tv_sec);
  return clock_compare(&first_end, &second_end);
}

int kernel_wakeup()
{
  t_kernel_callback *wakeup;
  struct timeval end;
  struct timeval *time;
  int count;

  count = 0;
  wakeup = list_get_begin(&g_kernel->callbacks);
  time = clock_get_time();
  logger_debug("[KERNEL] Start wakeup");
  while (wakeup)
    {
      end = wakeup->begin;
      logger_debug("[KERNEL] Flotting point 1");
      clock_move_date(&end, wakeup->time);
      logger_debug("[KERNEL] Flotting point 2");
      if (clock_compare(time, &end) > 0)
	{
          logger_debug("[KERNEL] Flotting point 3");
	  list_pop_begin(&g_kernel->callbacks);
          logger_debug("[KERNEL] Flotting point 4");
	  (*wakeup->callback)(wakeup->param, KN_ERROR_OK);
          logger_debug("[KERNEL] Flotting point 5");
	  free(wakeup);
          logger_debug("[KERNEL] Flotting point 6");
	  count++;
          logger_debug("[KERNEL] Flotting point 7");
	}
      else
	return count;
      wakeup = list_get_begin(&g_kernel->callbacks);
    }
  logger_debug("[KERNEL] End wakeup");
  return count;
}
