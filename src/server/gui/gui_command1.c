
#include "gui.h"
#include "parser.h"

void gui_command_msz(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];

  (void) command;
  snprintf(buffer, GUI_BUFFER_SIZE, "msz %i %i", game_width(), game_height());
  gui_send(gui, buffer);
}

void gui_command_mct(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_tile *tile;
  int x;
  int y;
  int i;
  int j;

  (void) command;
  x = game_width();
  y = game_height();
  i = 0;
  while (i < y)
    {
      j = 0;
      while (j < x)
	{
	  tile = world_get_tile(i, j);
	  snprintf(buffer, GUI_BUFFER_SIZE, "bct %i %i %i %i %i %i %i %i %i",
		   tile->pos_x, tile->pos_y,
		   tile->rc_food, tile->rc_linemate, tile->rc_deraumere,
		   tile->rc_sibur, tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
	  gui_send(gui, buffer);
	  j++;
	}
      i++;
    }
}

void gui_command_bct(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_command *parse;
  t_tile *tile;

  parse = parser_parse(command, "bct %i %i");
  if (parse)
    {
      tile = world_get_tile(parser_get_int(parse, 0), parser_get_int(parse, 1));
      snprintf(buffer, GUI_BUFFER_SIZE, "bct %i %i %i %i %i %i %i %i %i",
	       tile->pos_x, tile->pos_y,
	       tile->rc_food, tile->rc_linemate, tile->rc_deraumere,
	       tile->rc_sibur, tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
      gui_send(gui, buffer);
      parser_command_destroy(parse);
    }
}

void gui_command_tna(t_gui *gui, char *command)
{
  char buffer[GUI_BUFFER_SIZE];
  t_team *team;

  (void) command;
  lforeach(game_get_teams(), team)
  {
    snprintf(buffer, GUI_BUFFER_SIZE, "tna %s", team->name);
    gui_send(gui, buffer);
  }
}
