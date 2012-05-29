/*
** player_left.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:46:48 2012 damien vezant
** Last update Tue May 29 08:17:06 2012 damien vezant
*/

#include	"game.h"

void		player_left(t_player *player)
{
  if (player->orientation != NORTH)
    --player->orientation;
  else
    player->orientation = WEST;
}
