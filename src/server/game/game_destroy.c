/*
** game_destroy.c for zappy in /home/lukior/Zappy
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Fri Jun  1 11:27:26 2012 damien vezant
** Last update Fri Jun  1 11:27:27 2012 damien vezant
*/

#include	"game.h"

void		game_destroy()
{
  int		idx;
  int		idy;

  idx = 0;
  idy = 0;
  while (idy < g_game_world->dimensions.y)
  {
    while (idx < g_game_world->dimensions.x)
    {
      list_clear(&g_game_world->world[idx * idy].players);
      ++idx;
    }
    idx = 0;
    ++idy;
  }
  free(g_game_world->world);
  free(g_game_world);
  map_clear(&g_team_map);
  map_clear(&g_autoplay_team);
}
