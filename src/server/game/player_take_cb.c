/*
** player_take.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:59:30 2012 damien vezant
** Last update Wed May 30 16:17:55 2012 damien vezant
*/

#include	"game.h"

extern t_world	*game_world;

void		player_take_cb(t_client *client, t_command *command)
{
  int		item;
  t_tile	*tile;
  int		*inventory;
  int		*ressources;

  item = parser_get_int(command, 1);
  tile = &game_world->world[client->player.position.x * client->player.position.y];
  ressources = (int *)&tile->ressources;
  inventory = (int *)&client->player.inventory;
  if (ressources[item] > 0)
    {
      ressources[item] -= 1;
      inventory[item] += 1;
    }
}
