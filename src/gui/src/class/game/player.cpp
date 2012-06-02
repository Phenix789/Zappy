#include "game.hpp"

namespace game
{
  player::player(int x, int y, int num) : number(num), pos_x(x), pos_y(y)
  { }

  player::~player()
  { }
}
