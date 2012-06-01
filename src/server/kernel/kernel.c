/*
** kernel.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:27:37 2012 quentin duval
** Last update Fri Jun  1 02:20:29 2012 quentin duval
*/

#include	"kernel.h"
#include "logger.h"

t_kernel	*g_kernel = NULL;

void		kernel_init()
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

bool		kernel_init_with_argv(int argc, char **argv)
{
  int index;
  int team;

  kernel_init();
  if (kernel_session_init(&g_kernel->listener, kernel_getopt_int(argc, argv, "-p", 3945)) &&
      kernel_client_init() &&
      kernel_game_init(kernel_getopt_int(argc, argv, "-x", 10), kernel_getopt_int(argc, argv, "-y", 10), kernel_getopt_int(argc, argv, "-c", 10)) &&
      kernel_clock_init(kernel_getopt_int(argc, argv, "-t", 100)))
    {
      index = kernel_retrieve_flag_index(argc, argv, "-n") + 1;
      team = 0;
      if (index == 0)
	return false;
      while (!IS_FLAG(argv[index]))
	{
	  kernel_add_team(argv[index++]);
	  team++;
	}
      game_world_dump();
      return team > 0;
    }
  return false;
}

void		kernel_destroy()
{
  list_free(&g_kernel->callbacks);
  logger_message("[KERNEL] Kernel destroy");
}
