/*
** player_forward.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:40:16 2012 damien vezant
** Last update Tue May 29 08:16:53 2012 damien vezant
*/

#include	"game.h"

void		player_forward(t_player *player)
{
  if (player->orientation == NORTH)
    player->position.y -= 1;
  else if (player->orientation == EAST)
    player->position.x += 1;
  else if (player->orientation == WEST)
    player->position.x -= 1;
  else if (player->orientation == SOUTH)
    player->position.y += 1;
}
