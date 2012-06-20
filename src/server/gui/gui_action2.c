
#include "gui.h"

void gui_action_take(t_player* player, t_item item)
{
  char buffer[GUI_BUFFER_SIZE];
  t_tile *tile;

  tile = player->tile;
  snprintf(buffer, GUI_BUFFER_SIZE, "pgt #%i %i", player->id, item);
  gui_send_all(buffer);
  snprintf(buffer, GUI_BUFFER_SIZE, "pin #%i %i %i %i %i %i %i %i %i %i",
	   player->id, player->ppos_x, player->ppos_y,
	   player->inv_food, player->inv_linemate, player->inv_deraumere,
	   player->inv_sibur, player->inv_mendiane, player->inv_phiras, player->inv_thystame);
  gui_send_all(buffer);
  snprintf(buffer, GUI_BUFFER_SIZE, "bct %i %i %i %i %i %i %i %i %i",
	   tile->pos_x, tile->pos_y,
	   tile->rc_food, tile->rc_linemate, tile->rc_deraumere,
	   tile->rc_sibur, tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
  gui_send_all(buffer);
}

void gui_action_drop(t_player* player, t_item item)
{
  char buffer[GUI_BUFFER_SIZE];
  t_tile *tile;

  tile = player->tile;
  snprintf(buffer, GUI_BUFFER_SIZE, "pdr #%i %i", player->id, item);
  gui_send_all(buffer);
  snprintf(buffer, GUI_BUFFER_SIZE, "pin #%i %i %i %i %i %i %i %i %i %i",
	   player->id, player->ppos_x, player->ppos_y,
	   player->inv_food, player->inv_linemate, player->inv_deraumere,
	   player->inv_sibur, player->inv_mendiane, player->inv_phiras, player->inv_thystame);
  gui_send_all(buffer);
  snprintf(buffer, GUI_BUFFER_SIZE, "bct %i %i %i %i %i %i %i %i %i",
	   tile->pos_x, tile->pos_y,
	   tile->rc_food, tile->rc_linemate, tile->rc_deraumere,
	   tile->rc_sibur, tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
  gui_send_all(buffer);
}
