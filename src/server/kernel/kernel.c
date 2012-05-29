
#include <unistd.h>
#include "kernel.h"

t_kernel *g_kernel = NULL;

t_kernel * kernel_create()
{
  if ((g_kernel = malloc(t_kernel)) == NULL)
    return NULL;
  return kernel_init(g_kernel);
}

t_kernel * kernel_init(t_kernel *kernel)
{
  list_init(&kernel->callbacks);
  return kernel;
}

void kernel_destroy(t_kernel *kernel)
{
  list_free(&kernel->callbacks);
}
