/*
** player_take.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:59:30 2012 damien vezant
** Last update Tue May 29 08:16:32 2012 damien vezant
*/

#include	"game.h"

void		player_take(t_item item, t_player *player)
{
  if (item == LINEMATE)
    ++player->inventory.linemate;
  else if (item == DERAUMERE)
    ++player->inventory.deraumere;
  else if (item == SIBUR)
    ++player->inventory.sibur;
  else if (item == MENDIANE)
    ++player->inventory.mendiane;
  else if (item == PHIRAS)
    ++player->inventory.phiras;
  else if (item == THYSTAME)
    ++player->inventory.thystame;
  else if (item == FOOD)
    ++player->inventory.food;
}
