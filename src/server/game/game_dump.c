/*
** game_world_dump.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Fri Jun  1 12:00:01 2012 damien vezant
** Last update Fri Jun  1 12:00:02 2012 damien vezant
*/

#include	"game.h"

extern t_game *g_game;

void game_world_dump()
{
  int idx;
  int idy;
  t_tile *tile;

  idy = 0;
  printf("World dump\n");
  while (idy < g_game->world.w_height)
    {
      idx = 0;
      while (idx < g_game->world.w_width)
	{
	  tile = world_get_tile(idx, idy);
	  printf("{%i %i:%i:%i:%i:%i:%i:%i} ",
	  list_size(&tile->players), tile->rc_food,
	  tile->rc_linemate, tile->rc_deraumere, tile->rc_sibur,
	  tile->rc_mendiane, tile->rc_phiras, tile->rc_thystame);
	  ++idx;
	}
      printf("\n");
      ++idy;
    }
}
