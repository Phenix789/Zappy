/*
** errors.h for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#ifndef __ERRORS_H__
#define __ERRORS_H__

#include <stdlib.h>
#include <stdarg.h>

#define ERROR_MALLOC "Malloc échoué\n"
#define ERROR_EXIT "Exit avec le code d'erreur %i\n"

void error_exit(char *pattern, int exit_code, ...);
void error_print(char *pattern, ...);
void error_vprint(char *pattern, va_list *arg);

#endif
