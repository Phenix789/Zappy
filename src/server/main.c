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

void server_usage()
{
  printf("Zappy Server\nUsage:\n");
  printf("-p numero du port (default 3945)\n");
  printf("-x largeur du Monde (default 10)\n");
  printf("-y hauteur du Monde (default 10)\n");
  printf("-n nom equipe 1 [nom equipe 2 [nom equipe n]]\n");
  printf("-c nombre de client par equipe (default 10)\n");
  printf("-t delai temporel d'execution des actions (default 100)\n");
}

int	main(int argc, char **argv)
{
  if (argc == 1)
    server_usage();
  else
    {
      logger_init(LG_ALLLOG, "zappy.log", LG_VERBOSE);
      if (kernel_init_with_argv(argc, argv))
	kernel_run();
      kernel_destroy();
    }
  return (0);
}
