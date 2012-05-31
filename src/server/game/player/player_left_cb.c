/*
** player_left.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:46:48 2012 damien vezant
** Last update Wed May 30 22:09:10 2012 damien vezant
*/

#include	"game.h"

void		player_left_end_cb(t_client *client, int error)
{
  if (!error)
    {
      if (client->player->orientation != OR_NORTH)
	--client->player->orientation;
      else
	client->player->orientation = OR_WEST;
      session_send(client, REP_OK);
    }
  else
    session_send(client, REP_KO);
}

void		player_left_start_cb(t_client *client, t_command *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, player_left_end_cb, client);
}
