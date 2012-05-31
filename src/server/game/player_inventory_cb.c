/*
** player_inventory.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:49:50 2012 damien vezant
** Last update Wed May 30 22:09:29 2012 damien vezant
*/

#include	"game.h"

void		player_inventory_end_cb(t_client *client, int error)
{
  if (!error)
    {
      session_send(client, REP_INVENTORY,
		   client->player->inventory.linemate,
		   client->player->inventory.deraumere,
		   client->player->inventory.sibur,
		   client->player->inventory.mendiane,
		   client->player->inventory.phiras,
		   client->player->inventory.thystame,
		   client->player->inventory.food);
    }
  else
    session_send(client, REP_KO);
}

void		player_inventory_start_cb(t_client *client, t_command *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, player_inventory_end_cb, client);
}
