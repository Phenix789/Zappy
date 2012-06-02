
#include "game.h"

extern t_game *g_game;

static void _game_start_team(t_team *team)
{
  t_player *player;

  while (team->available_slots > 0)
    {
      player = player_create(team, rand(), rand());
      game_add_free_player(player);
    }
}

bool game_start()
{
  if (list_size(&g_game->teams) == 0)
    return false;
  list_foreach(&g_game->teams, (feach) &_game_start_team);
  game_play_free_player();
  return true;
}

void game_play_free_player()
{
  logger_error("[GAME] Play free player not implemented!");
}
