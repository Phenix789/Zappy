/*
** player_right.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:44:17 2012 damien vezant
** Last update Wed May 30 22:09:01 2012 damien vezant
*/

#include	"game.h"

void		player_right_end_cb(t_client *client, int error)
{
  if (!error)
    {
      if (client->player->orientation != OR_WEST)
	++client->player->orientation;
      else
	client->player->orientation = OR_NORTH;
      client_send(client, REP_OK);
    }
  else
    client_send(client, REP_KO);
}

void		player_right_start_cb(t_client *client, char *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, (kn_wakeup_cb) player_right_end_cb, client);
}
