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

t_player	*game_autoplay_get_player(t_player *player)
{
  return (map_get(&g_autoplay_team, &player->id));
}
