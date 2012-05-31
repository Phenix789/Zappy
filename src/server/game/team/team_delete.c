/*
** team_delete.c for zappy in /home/lukior/Zappy/src/game/player
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 06:53:33 2012 damien vezant
** Last update Tue May 29 07:15:19 2012 damien vezant
*/

#include	"game.h"

static void	_clean_pair(void *first, void *second)
{
  (void)first;
  player_delete(second);
}

void		team_delete(char *name)
{
  t_team	*tmp;

  tmp = map_get(&g_team_map, name);
  map_foreach(&tmp->player_map, _clean_pair);
  map_clear(&tmp->player_map);
  free(tmp->name);
  free(tmp);
}
