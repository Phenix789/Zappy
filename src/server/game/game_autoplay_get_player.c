/*
** game_autoplay_get_player.c for zappy in /home/lukior/Zappy/src/player
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 04:46:21 2012 damien vezant
** Last update Tue May 29 07:07:09 2012 damien vezant
*/

#include	"game.h"

extern t_map	*autoplay_team;

t_player	*game_autoplay_get_player(t_player *player)
{
  return (map_get(autoplay_team, &player->id));
}
