
#include "game.h"

extern t_game *g_game;

static int _game_player_in_team(t_player *player, t_team *team)
{
  if (player->team == team)
    return 0;
  return 1;
}

void game_add_free_player(t_player *player)
{
  list_add_end(&g_game->slots, player);
}

void game_remove_free_player(t_player *player)
{
  list_pop(&g_game->slots, player);
}

t_player *game_get_slot(char *name)
{
  t_team *team;
  t_player *player;

  logger_verbose("[GAME] Search team '%s'", name);
  team = game_get_team(name);
  if (team && team->free_slots > 0)
    {
      logger_verbose("[GAME] Team %s found", name);
      player = list_get_to_param(&g_game->slots, (fpredp) &_game_player_in_team, team);
      if (player)
	{
	  logger_verbose("[GAME] Player %i found", player->id);
	  game_remove_free_player(player);
	  team->free_slots--;
	  return player;
	}
    }
  return NULL;
}
