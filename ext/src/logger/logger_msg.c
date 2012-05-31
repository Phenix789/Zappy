/*
** logger_msg.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include <stdarg.h>

#include "logger.h"

extern t_logger *g_logger;

static int logger_write(int level, char *message, va_list *varg)
{
  char buffer[1024];

  if (!logger_is_init())
    logger_init(LG_LOG, LOGGER_FILENAME, LG_VERBOSE);
  if (logger_is_init() && g_logger->level & level)
    {
      vsnprintf(buffer, 1024, message, *varg);
      if (g_logger->verbose)
	printf("%s\n", buffer);
      return fprintf(g_logger->file, "%s\n", buffer);
    }
  return -1;
}

int logger_message(char *message, ...)
{
  va_list varg;
  int v;

  va_start(varg, message);
  v = logger_write(LG_MESSAGE, message, &varg);
  va_end(varg);
  return v;
}

int logger_warning(char *message, ...)
{
  va_list varg;
  int v;

  va_start(varg, message);
  v = logger_write(LG_WARNING, message, &varg);
  va_end(varg);
  return v;
}

int logger_error(char *message, ...)
{
  va_list varg;
  int v;

  va_start(varg, message);
  v = logger_write(LG_ERROR, message, &varg);
  va_end(varg);
  return v;
}

int logger_debug(char *message, ...)
{
  va_list varg;
  int v;

  va_start(varg, message);
  v = logger_write(LG_DEBUG, message, &varg);
  va_end(varg);
  return v;
}
