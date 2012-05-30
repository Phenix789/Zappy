/*
** player_expulse_cb.c for zappy in /home/lukior/Zappy/src/server/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Wed May 30 17:08:35 2012 damien vezant
** Last update Wed May 30 20:44:30 2012 damien vezant
*/

#include	"game.h"

extern t_world	*game_world;

static void	forward(t_player *player)
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

void		player_expulse_end_cb(t_client *client, int error)
{
  t_tile	*tile;
  t_list	*players;
  int		i;
  t_player	*pawn;
  int		direction;

  i = 0;
  if (!error)
    {
      tile = &game_world->world[client->player.position.x * client->player.position.y];
      players = &tile->players;
      direction = client->player.orientation;
      while (i < players->size)
	{
	  pawn = list_get_at(players, i);
	  if (pawn != client->player)
	    {
	      pawn->orientation = direction;
	      forward(pawn);
	    }
	  ++i;
	}
      session_send(client, REP_OK);
    }
  else
    session_send(client, REP_KO);
}

void		player_expulse_start_cb(t_client *client, t_command *command)
{
  (void)command;
  register_wakeup(DELAY_STANDARD, player_expulse_end_cb, client);
}
