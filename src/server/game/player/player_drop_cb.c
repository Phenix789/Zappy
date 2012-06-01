/*
** player_drop.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 08:03:53 2012 damien vezant
** Last update Wed May 30 20:30:25 2012 damien vezant
*/

#include	"game.h"

static int	item;

void		player_drop_end_cb(t_client *client, int error)
{
  int		*ressources;
  int		*inventory;
  t_tile	*tile;

  logger_debug("[GAME] ");
  if (!error)
    {
      tile = player_get_tile(client->player);
      ressources = (int *)&tile->ressources;
      inventory = (int *)&client->player->inventory;
      if (inventory[item] > 0)
	{
	  inventory[item] -= 1;
	  ressources[item] += 1;
	  session_send(client, REP_OK);
	}
      else
	session_send(client, REP_KO);
    }
  else
    session_send(client, REP_KO);
}

void		player_drop_start_cb(t_client *client, t_command *command)
{
  int		*inventory;

  item = parser_get_int(command, 1);
  inventory = (int *)&client->player->inventory;
  if (inventory[item] > 0)
    kernel_register_wakeup(DELAY_STANDARD, player_drop_end_cb, client);
  else
    session_send(client, REP_KO);
}
