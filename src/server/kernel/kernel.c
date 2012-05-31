/*
** kernel.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Thu May 31 16:27:37 2012 quentin duval
** Last update Thu May 31 17:26:39 2012 quentin duval
*/

#include	"kernel.h"

t_kernel	*g_kernel = NULL;

t_kernel	*kernel_create()
{
  if ((g_kernel = malloc(sizeof(t_kernel))) == NULL)
    return (NULL);
  kernel_init(g_kernel);
  return (g_kernel);
}

void		kernel_init()
{
  list_init(&g_kernel->callbacks);
  g_kernel->init = 0;
  if (!kernel_network_init(3945))
    printf("network init error\n");
  else
    printf("network initialisation complete\n");
  if (!kernel_session_init())
    printf("session manager init error\n");
  else
    printf("session initialisation complete\n");
  if (!clock_create())
    printf("clock init error\n");
  else
    printf("clock initialisation complete\n");
  game_init();
}

void		kernel_destroy(t_kernel *kernel)
{
  list_free(&kernel->callbacks);
}
