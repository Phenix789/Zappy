/*
** kernel_signal.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include <signal.h>
#include "kernel.h"

extern t_kernel *g_kernel;

void kernel_signal()
{
  signal(SIGSEGV, &kernel_signal_handle);
  signal(SIGTERM, &kernel_signal_handle);
  signal(SIGINT, &kernel_signal_handle);
  signal(SIGFPE, &kernel_signal_handle);
}

void kernel_signal_handle(int sig)
{
  logger_error("[KERNEL] Signal catched %i", sig);
  signal(sig, NULL);
  kernel_destroy();
  logger_destroy();
  kill(getpid(), sig);
}
