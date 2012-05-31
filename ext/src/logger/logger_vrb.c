
#include <stdarg.h>

#include "logger.h"

int logger_verbose(char *message, ...)
{
  char buffer1[1024];
  char buffer2[1024];
  va_list varg;
  int v;

  va_start(varg, message);
  snprintf(buffer1, 1024, "{%s} %s", "verbose", message);
  vsnprintf(buffer2, 1024, buffer1, varg);
  v = printf("%s\n", buffer2);
  va_end(varg);
  return v;
}
