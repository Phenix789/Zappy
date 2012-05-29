/*
** game_player_add.c for zappy in /home/lukior/Zappy/src/player
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 04:01:10 2012 damien vezant
** Last update Tue May 29 07:11:17 2012 damien vezant
*/

#include	"game.h"

extern t_map	*team_map;

void		game_player_add(char *team, t_player *player)
{
  t_team	*tmp;

  if ((tmp = map_get(team_map, team)) != NULL)
    map_add(tmp->player_map, &player->id, player);
}
