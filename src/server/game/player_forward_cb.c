/*
** player_forward.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:40:16 2012 damien vezant
** Last update Wed May 30 19:56:11 2012 damien vezant
*/

#include	"game.h"

extern t_tile	*world;
extern t_world	game_world;

static void	_forward_player(int x, int y, t_player *player)
{
  player->position.x += x;
  player->position.y += y;
  if (player->position.x > game_world.dimensions.x)
    player->position.x = 0;
  else if (player->position.x < 0)
    player->position.x = game_world.dimensions.x;
  else if (player->position.y > game_world.dimensions.y)
    player->position.y = 0;
  else if (player->position.y < 0)
    player->position.y = game_world.dimensions.y;
}

void		player_forward_end_cb(t_client *client, int error)
{
  if (!error)
    {
      list_pop(world[client->player->position.x * client->player->position.y].players, client->player);
      if (client->player.orientation == NORTH)
	_forward_player(0, -1, client->player);
      else if (client->player.orientation == SOUTH)
	_forward_player(0, 1, client->player);
      else if (client->player.orientation == EAST)
	_forward_player(1, 0, client->player);
      else if (client->player.orientation == WEST)
	_forward_player(-1, 0, client->player);
      session_send(client, REP_OK);
    }
  else
    session_send(client, REP_KO);
}

void		player_forward_start_cb(t_client *client, t_command *command)
{
  register_wakeup(DELAY_STANDARD, player_forward_end_cb, client);
}
