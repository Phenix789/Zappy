
#include "kernel.h"

extern t_kernel *g_kernel;

bool kernel_add_team(char* team)
{
  logger_message("[KERNEL] Add team %s", team);
  if (kernel_is_init(KN_SV_GAME))
    return team_new(team) != NULL;
  return false;
}
