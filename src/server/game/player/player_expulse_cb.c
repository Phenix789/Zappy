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

static void	forward(t_player *player)
{
  list_pop(&player_get_tile(player)->players, player);
  if (player->orientation == OR_NORTH)
    {
      if ((player->position.y -= 1) < 0)
        player->position.y = g_game_world->dimensions.y - 1;
    }
  else if (player->orientation == OR_EAST)
    {
      if ((player->position.x += 1) >= g_game_world->dimensions.x)
        player->position.x = 1;
    }
  else if (player->orientation == OR_WEST)
    {
      if ((player->position.x -= 1) < 0)
        player->position.x = g_game_world->dimensions.x - 1;
    }
  else if (player->orientation == OR_SOUTH)
    {
      if ((player->position.y += 1) >= g_game_world->dimensions.y)
        player->position.y = 0;
    }
  list_add_end(&player_get_tile(player)->players, player);
}

void		player_expulse_end_cb(t_client *client, int error)
{
  t_tile	*tile;
  t_list	*players;
  unsigned int	i;
  t_player	*pawn;
  int		direction;

  i = 0;
  if (!error)
    {
      tile = player_get_tile(client->player);
      players = &tile->players;
      direction = client->player->orientation;
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
  kernel_register_wakeup(DELAY_STANDARD, player_expulse_end_cb, client);
}
