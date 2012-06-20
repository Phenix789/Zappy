
#include "gui.h"

extern t_gui_manager *g_gui_manager;

void gui_action_forward(t_player *player)
{
  char buffer[GUI_BUFFER_SIZE];

  snprintf(buffer, GUI_BUFFER_SIZE, "ppo #%i %i %i %i", player->id, player->ppos_x, player->ppos_y, player->orientation + 1);
  list_foreach_param(&g_gui_manager->guis, (feachp) &gui_send, buffer);
}

void gui_action_left(t_player *player)
{
  gui_action_forward(player);
}

void gui_action_right(t_player *player)
{
  gui_action_forward(player);
}
