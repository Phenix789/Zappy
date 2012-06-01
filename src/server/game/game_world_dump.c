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

void		game_world_dump()
{
  int		idx;
  int		idy;
  t_tile	*tile;
  t_inventory	*assets;

  idx = 0;
  idy = 0;
  printf("World dump\n");
  while (idy < g_game_world->dimensions.y)
  {
    while (idx < g_game_world->dimensions.x)
    {
      tile = &g_game_world->world[idx + (idy * g_game_world->dimensions.x)];
      assets = &tile->ressources;
      printf("{%i %i:%i:%i:%i:%i:%i:%i} ", list_size(&tile->players), assets->food,
	     assets->linemate, assets->deraumere, assets->sibur,
	     assets->mendiane, assets->phiras, assets->thystame);
      ++idx;
    }
    printf("\n");
    idx = 0;
    ++idy;
  }
}