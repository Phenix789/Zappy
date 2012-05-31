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

void		kernel_init()
{
  if ((g_kernel = malloc(sizeof(t_kernel))) == NULL)
    return;
  list_init(&g_kernel->callbacks);
  socket_init(&g_kernel->listener);
  g_kernel->init = 0;
  g_kernel->run = false;
/*

  if (!kernel_network_init(KN_DEFAULT_PORT))
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
*/
}

void		kernel_destroy()
{
  list_free(&g_kernel->callbacks);
}
