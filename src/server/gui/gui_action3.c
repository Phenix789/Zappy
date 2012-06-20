
#include "gui.h"

void gui_action_broadcast(t_player *player, char *msg)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "pbc #%i %s", player->id, msg);
  gui_send_all(buffer);
}

void gui_action_expulse(t_player *player)
{
  (void) player;
  logger_error("[GUI] Expulse not implemented!");
}
