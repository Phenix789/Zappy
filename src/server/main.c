/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src/server
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 03:09:00 2012 quentin duval
** Last update Thu May 31 16:34:10 2012 quentin duval
*/

#include	"kernel.h"
#include "logger.h"

int	main(int argc, char **argv)
{
  logger_init(LG_ALLLOG, "zappy.log", LG_VERBOSE);
  kernel_init_with_argv(argc, argv);
  kernel_run();
  kernel_destroy();
  return (0);
}
