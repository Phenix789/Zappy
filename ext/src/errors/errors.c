/*
** error.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include <stdio.h>
#include "errors.h"

void error_exit(char *pattern, int exit_code, ...)
{
  va_list arg;

  va_start(arg, exit_code);
  error_vprint(pattern, &arg);
  va_end(arg);
  error_print(ERROR_EXIT, exit_code);
  exit(exit_code);
}

void error_print(char *pattern, ...)
{
  va_list arg;

  va_start(arg, pattern);
  error_vprint(pattern, &arg);
  va_end(arg);
}

void error_vprint(char *pattern, va_list *arg)
{
  vfprintf(stderr, pattern, *arg);
  fprintf(stderr, "\n");
}
