/*
** player_drop.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 08:03:53 2012 damien vezant
** Last update Wed May 30 16:11:07 2012 damien vezant
*/

#include	"game.h"

extern t_world	*game_world;

void		player_drop_cb(t_client *client, t_command *command)
{
  int		item;
  int		*inventory;
  int		*ressources;
  t_tile	*tile;

  tile = &game_world->world[client->player.position.x * client->player.position.y];
  item = parser_get_int(command, 1);
  inventory = &client->player.inventory;
  ressources = &tile->ressources;
  if (inventory[item] > 0)
    {
      inventory[item] -= 1;
      ressources[item] += 1;
    }
}
