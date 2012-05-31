/*
** player_take.c for zappy in /home/lukior/Zappy/src/game
** 
** Made by damien vezant
** Login   <vezant_d@epitech.net>
** 
** Started on  Tue May 29 07:59:30 2012 damien vezant
** Last update Wed May 30 20:40:28 2012 damien vezant
*/

#include	"game.h"

static int	item;

void		player_take_end_cb(t_client *client, int error)
{
  int		*inventory;
  int		*ressources;
  t_tile	*tile;

  if (!error)
    {
      tile = player_get_tile(client->player);
      ressources = (int *)&tile->ressources;
      inventory = (int *)&client->player->inventory;
      if (ressources[item] > 0)
	{
	  ressources[item] -= 1;
	  inventory[item] += 1;
	  session_send(client, REP_OK);
	}
      else
	session_send(client, REP_KO);
    }
  else
    session_send(client, REP_KO);
}

void		player_take_start_cb(t_client *client, t_command *command)
{
  t_tile	*tile;
  int		*ressources;

  item = parser_get_int(command, 1);
  tile = player_get_tile(client->player);
  ressources = (int *)&tile->ressources;
  if (ressources[item] > 0)
    kernel_register_wakeup(DELAY_STANDARD, player_take_end_cb, client);
  else
    session_send(client, REP_KO);
}
