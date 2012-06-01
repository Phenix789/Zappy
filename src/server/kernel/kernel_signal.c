
#include <signal.h>
#include "kernel.h"

extern t_kernel *g_kernel;

void kernel_signal()
{
  signal(SIGSEGV, &kernel_signal_handle);
  signal(SIGTERM, &kernel_signal_handle);
  signal(SIGINT, &kernel_signal_handle);
}

void kernel_signal_handle(int sig)
{
  logger_error("[KERNEL] Signal catched %i", sig);
  kernel_destroy();
  logger_destroy();
  signal(sig, NULL);
  kill(getpid(), sig);
}
