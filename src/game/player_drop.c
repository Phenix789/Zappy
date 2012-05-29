/*
** player_drop.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 08:03:53 2012 damien vezant
** Last update Tue May 29 08:26:05 2012 damien vezant
*/

#include	"game.h"

int		player_drop(t_item item, t_player *player)
{
  if (item == LINEMATE && player->inventory.linemate > 0)
    return (--player->inventory.linemate);
  else if (item == DERAUMERE && player->inventory.deraumere > 0)
    return (--player->inventory.deraumere);
  else if (item == SIBUR && player->inventory.sibur > 0)
    return (--player->inventory.sibur);
  else if (item == MENDIANE && player->inventory.mendiane > 0)
    return (--player->inventory.mendiane);
  else if (item == PHIRAS && player->inventory.phiras > 0)
    return (--player->inventory.phiras);
  else if (item == THYSTAME && player->inventory.thystame > 0)
    return (--player->inventory.thystame);
  else if (item == FOOD && player->inventory.food > 0)
    return (--player->inventory.food);
  else
    return (-1);
}
