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
      client_send(client, REP_INVENTORY,
		   client->player->inv_food,
		   client->player->inv_linemate,
		   client->player->inv_deraumere,
		   client->player->inv_sibur,
		   client->player->inv_mendiane,
		   client->player->inv_phiras,
		   client->player->inv_thystame);
    }
  else
    client_send(client, REP_KO);
}

void		player_inventory_start_cb(t_client *client, char *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, (kn_wakeup_cb) player_inventory_end_cb, client);
}
