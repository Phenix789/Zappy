
#include "game.h"

extern t_game *g_game;

void world_add_player(t_player *player, int x, int y)
{
  t_tile *tile;

  tile = world_get_tile(x, y);
  player->tile = tile;
  list_add_end(&tile->players, player);
}

void world_remove_player(t_player *player)
{
  if (player->tile)
    {
      list_pop(&player->tile->players, player);
      player->tile = NULL;
    }
}

bool world_move_player(t_player *player)
{
  return world_move_to(player, player->orientation);
}

bool world_move_to(t_player *player, t_orientation direction)
{
  int x;
  int y;

  if (player->tile)
    {
      x = player->ppos_x;
      y = player->ppos_y;
      if (direction == OR_EAST)
	y -= 1;
      else if (direction == OR_NORTH)
	x += 1;
      else if (direction == OR_WEST)
	y += 1;
      else if (direction == OR_SOUTH)
	x -= 1;
      world_remove_player(player);
      world_add_player(player, x, y);
      return true;
    }
  return false;
}

t_tile *world_get_tile(int x, int y)
{
  int w;
  int h;

  w = g_game->world.w_width;
  h = g_game->world.w_height;
  if (x < 0 || x > w)
    x = ((x % w) + w) % w;
  if (y < 0 || y > h)
    y = ((y % h) + h) % h;
  return &g_game->world.tiles[y * w + x];
}
