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

int	main()
{
  kernel_create();
  kernel_run();
  kernel_destroy();
  return (0);
}
