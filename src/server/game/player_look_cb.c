/*
** player_look_cb.c for zappy in /home/lukior/Zappy/src/server/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Wed May 30 14:13:02 2012 damien vezant
** Last update Wed May 30 22:09:19 2012 damien vezant
*/

#include	"game.h"

void		player_look_end_cb(t_client *client, int error)
{
  (void) error;
  session_send(client, REP_KO);
}

void		player_look_start_cb(t_client *client, t_command *command)
{
  (void)command;
  kernel_register_wakeup(DELAY_STANDARD, player_look_end_cb, client);
}
