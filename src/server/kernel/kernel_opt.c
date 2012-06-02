/*
** kernel_opt.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include <string.h>
#include "kernel.h"

int kernel_retrieve_flag_index(int argc, char **argv, char *flag)
{
  int i;

  i = 0;
  while (i < argc)
    {
      if (strcmp(argv[i], flag) == 0)
	return i;
      i++;
    }
  return -1;
}

char *kernel_getopt(int argc, char **argv, char *flag, char *defaut)
{
  int value;

  value = kernel_retrieve_flag_index(argc, argv, flag);
  if (value == -1 || IS_FLAG(argv[value + 1]))
    return defaut;
  return argv[value + 1];
}

int kernel_getopt_int(int argc, char **argv, char *flag, int defaut)
{
  char *val;

  val = kernel_getopt(argc, argv, flag, NULL);
  if (val)
    return atoi(val);
  return defaut;
}
