/*
** player_forward.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:40:16 2012 damien vezant
** Last update Wed May 30 22:08:54 2012 damien vezant
*/

#include	"game.h"

void		player_forward_end_cb(t_client *client, int error)
{
  if (!error)
    {
      world_move_player(client->player);
      client_send(client, REP_OK);
    }
  else
    client_send(client, REP_KO);
}

void		player_forward_start_cb(t_client *client, char *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, (kn_wakeup_cb) player_forward_end_cb, client);
}
