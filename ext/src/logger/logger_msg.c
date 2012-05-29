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
  if (!logger_is_init())
    logger_init(LG_LOG, LOGGER_FILENAME);
  if (logger_is_init() && g_logger->level & level)
    return vfprintf(g_logger->file, message, *varg);
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
