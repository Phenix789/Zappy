/*
** game_init.c for zappy in /home/lukior/Zappy/src/game
**
** Made by damien vezant
** Login   <vezant_d@epitech.net>
**
** Started on  Tue May 29 07:21:02 2012 damien vezant
** Last update Fri Jun  1 16:51:20 2012 quentin duval
*/

#include "game.h"
#include "client.h"

t_game *g_game = NULL;

static void _game_register()
{
  clm_command_register("avance", "%s", player_forward_start_cb);
  clm_command_register("droite", "%s", player_right_start_cb);
  clm_command_register("gauche", "%s", player_left_start_cb);
  clm_command_register("voir", "%s", player_look_start_cb);
  clm_command_register("inventaire", "%s", player_inventory_start_cb);
  clm_command_register("prend", "%s %s", player_take_start_cb);
  clm_command_register("pose", "%s %s", player_drop_start_cb);
  clm_command_register("expulse", "%s", player_expulse_start_cb);
  //clm_command_register("broadcast", "%s %s", player_broadcast_start_cb);
  clm_command_register("incantation", "%s", player_incantation_start_cb);
  clm_command_register("fork", "%s", player_fork_start_cb);
  clm_command_register("connect_nbr", "%s", player_connect_nbr_cb);
  clm_command_register("-", "%s", player_death_cb);
}

static void _game_world_tile(t_tile *tile)
{
  tile->rc_food = rand() % 4;
  tile->rc_linemate = rand() % 2;
  if ((rand() % 100) < 25)
    tile->rc_deraumere = 1;
  if ((rand() % 100) < 20)
    tile->rc_sibur = 1;
  if ((rand() % 100) < 15)
    tile->rc_mendiane = 1;
  if ((rand() % 100) < 10)
    tile->rc_phiras = 1;
  if ((rand() % 100) < 5)
    tile->rc_thystame = 1;
}

static bool _game_world_init(int x, int y)
{
  int idx;
  int idy;

  if (x > 0 && x < WORLD_MAX_SIZE && y > 0 && y < WORLD_MAX_SIZE)
    {
      g_game->world.tiles = calloc(x * y, sizeof(t_tile));
      g_game->world.w_width = x;
      g_game->world.w_height = y;
      idy = 0;
      while (idy < y)
	{
	  idx = 0;
	  while (idx < x)
	    {
	      _game_world_tile(&g_game->world.tiles[(idy * x) + idx]);
	      idx++;
	    }
	  idy++;
	}
      return true;
    }
  logger_error("[GAME] World size is too big : %i:%i", x, y);
  return false;
}

bool game_init(int x, int y, int nb_slots)
{
  logger_verbose("[GAME] Starting game init");
  if (!(g_game = malloc(sizeof(t_game))))
    return false;
  if (_game_world_init(x, y))
    {
      list_init(&g_game->teams);
      list_init(&g_game->slots);
      g_game->nb_slots = nb_slots;
      _game_register();
      logger_verbose("[GAME] game module correctly initialized");
      return true;
    }
  return false;
}
