/*
** kernel.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:27:37 2012 quentin duval
** Last update Fri Jun  1 02:20:29 2012 quentin duval
*/

#include "kernel.h"
#include "logger.h"

t_kernel *g_kernel = NULL;

void kernel_init()
{
  if (g_kernel != NULL)
    return;
  if ((g_kernel = malloc(sizeof(t_kernel))) == NULL)
    return;
  list_init(&g_kernel->callbacks);
  socket_init(&g_kernel->listener);
  g_kernel->init = 0;
  g_kernel->run = false;
  kernel_signal();
  logger_message("[KERNEL] Kernel init");
}

#define kopt kernel_get_opt
#define kopti kernel_getopt_int
bool kernel_init_with_argv(int argc, char **argv)
{
  int index;
  int team;

  kernel_init();
  if (kernel_session_init(&g_kernel->listener, kopti(argc, argv, "-p", 3945)) &&
      kernel_client_init() &&
      kernel_game_init(kopti(argc, argv, "-x", 10),
		       kopti(argc, argv, "-y", 10),
		       kopti(argc, argv, "-c", 10)) &&
      kernel_clock_init(kopti(argc, argv, "-t", 100)))
    {
      index = kernel_retrieve_flag_index(argc, argv, "-n") + 1;
      if (index == 0)
	return false;
      team = 0;
      while (!IS_FLAG(argv[index]))
	{
	  kernel_add_team(argv[index++]);
	  team++;
	}
      return team > 0;
    }
  return false;
}

void kernel_destroy()
{
  //@todo destroy multiple service
  list_free(&g_kernel->callbacks);
  logger_message("[KERNEL] Kernel destroy");
}
