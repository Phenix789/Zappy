/*
** game_autoplay_add_player.c for zappy in /home/lukior/Zappy/src/player
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 04:44:22 2012 damien vezant
** Last update Tue May 29 07:06:49 2012 damien vezant
*/

#include	"game.h"

extern t_map	*autoplay_team;

void		game_autoplay_add_player(t_player *player)
{
  map_add(autoplay_team, &(player->id), player);
}
