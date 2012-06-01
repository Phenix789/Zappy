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
  while (idy < g_game_world->dimensions.y)
  {
    while (idx < g_game_world->dimensions.x)
    {
      tile = &g_game_world->world[idx * idy];
      assets = &g_game_world->item_count;
      printf("tile [%d:%d]\nnb players %d\nlinemate %d\nderaumere %d\nsibur %d\n",
	     tile->coord.x, tile->coord.y, list_size(&tile->players), assets->linemate, assets->deraumere, assets->sibur);
      printf("mendiane %d\nphiras %d\nthystame %d\nfood %d\n\n",
	     assets->mendiane, assets->phiras, assets->thystame, assets->food);
      ++idx;
    }
    x = 0;
    ++idy;
  }
}