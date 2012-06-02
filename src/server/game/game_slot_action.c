
#include "game.h"

void game_action_choose(t_player *player)
{
  int random;

  random = rand() % 100;
  if (random < 50)
    game_action_move(player);
  else if (random < 75)
    game_action_left(player);
  else
    game_action_right(player);
}

void game_action_move(t_player *player)
{
  (void) player;
}

void game_action_left(t_player *player)
{
  (void) player;
}

void game_action_right(t_player *player)
{
  (void) player;
}
