/*
** player_expulse_cb.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Wed May 30 17:08:35 2012 damien vezant
** Last update Wed May 30 20:44:30 2012 damien vezant
*/

#include "game.h"
#include "client.h"

void		player_expulse_end_cb(t_client *client, int error)
{
  t_client *client_player;
  t_tile	*tile;
  t_list_node *node;
  t_list_node *next;

  if (!error)
    {
      tile = client->player->tile;
      node = tile->players.head;
      while (node)
	{
	  next = node->next;
	  if (node->data != client->player)
	    {
	      world_move_to(node->data, client->player->orientation);
	      client_player = clm_retrieve_from_player(node->data);
	      if (client_player)
		{
		  client_send(client_player, "deplacement: %i", 0);
		}
	      //player_action_cancel(node->data);
	    }
	  node = next;
	}
      client_send(client, REP_OK);
    }
  else
    client_send(client, REP_KO);
}

void		player_expulse_start_cb(t_client *client, char *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, (kn_wakeup_cb) player_expulse_end_cb, client);
}
