/*
** player_inventory.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:49:50 2012 damien vezant
** Last update Tue May 29 08:25:17 2012 damien vezant
*/

#include	"game.h"

char		*player_inventory(t_player *player)
{
  char		buff[256];

  sprintf(buff, "food %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d",
	  player->inventory.food,
	  player->inventory.linemate,
	  player->inventory.deraumere,
	  player->inventory.sibur,
	  player->inventory.mendiane,
	  player->inventory.phiras,
	  player->inventory.thystame);
  return (strdup(buff));
}
