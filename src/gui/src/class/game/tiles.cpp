#include "game.hpp"

game::tiles::tiles()
{
  for (int i = 0; i < 7; i++)
    this->ressources[i] = 0;
}
