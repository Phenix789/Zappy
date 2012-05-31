/*
 * * player_get_tile.c for zappy in /home/lukior/Zappy/src/game
 **
 ** Made by damien vezant
 ** Login   <vezant_d@epitech.net>
 **
 ** Started on  Tue May 29 08:03:53 2012 damien vezant
 ** Last update Wed May 30 20:30:25 2012 damien vezant
 */

#include	"game.h"

t_tile		*player_get_tile(t_player *player)
{
  return (&game_world->world[player->position.x * player->position.y]);
}