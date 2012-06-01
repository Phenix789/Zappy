/*
** kernel_team.c for zappy in /home/duval_q//Documents/projects/zappy/src/server/kernel
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Thu May 31 16:30:58 2012 quentin duval
** Last update Fri Jun  1 20:57:33 2012 quentin duval
*/

#include "kernel.h"

extern t_kernel *g_kernel;

bool kernel_add_team(char* team)
{
  logger_message("[KERNEL] Add team %s", team);
  if (kernel_is_init(KN_SV_GAME))
    return team_new(team) != NULL;
  return false;
}
