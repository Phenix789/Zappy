
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
