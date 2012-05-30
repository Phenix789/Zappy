/*
** player_forward.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:40:16 2012 damien vezant
** Last update Wed May 30 13:57:29 2012 damien vezant
*/

#include	"game.h"

extern t_tile	*world;
extern t_world	game_world;

void		player_forward_cb(t_client *client, t_command *command)
{
  (void)command;
  list_pop(world[client->player->position.x * client->player->position.y].players, client->player);
  if (client->player->orientation == NORTH)
    {
      if ((client->player->position.y -= 1) < 0)
	client->player->position.y = game_world.dimensions.y;
    }
  else if (client->player->orientation == EAST)
    {
      if ((client->player->position.x += 1) > game_world.dimensions.x)
	client->player->position.x = 1;
    }
  else if (client->player->orientation == WEST)
    {
      if ((client->player->position.x -= 1) < 0)
	client->player->position.x = game_world.dimensions.x;
    }
  else if (client->player->orientation == SOUTH)
    {
      if ((client->player->position.y += 1) > game_world.dimensions.y)
	client->player->position.y = 0;
    }
  list_add_end(world[client->player->position.x * client->player->position.y].players, client->player);
}
