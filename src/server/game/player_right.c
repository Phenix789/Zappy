/*
** player_right.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:44:17 2012 damien vezant
** Last update Tue May 29 08:16:59 2012 damien vezant
*/

#include	"game.h"

void		player_right(t_player *player)
{
  if (player->orientation != WEST)
    ++player->orientation;
  else
    player->orientation = NORTH;
}
