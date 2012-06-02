
#include "game.h"

extern t_game *g_game;

int game_width()
{
  if (g_game)
    return g_game->world.w_width;
  return 0;
}

int game_height()
{
  if (g_game)
    return g_game->world.w_height;
  return 0;
}
