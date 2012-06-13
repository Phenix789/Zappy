#include <iostream>
#include "game.hpp"

game::tiles::tiles()
{
  for (int i = 0; i < 7; i++)
    this->ressources[i] = 0;
}

void	game::tiles::set(ress type, int nb)
{
  if (type < FOOD || type > THYSTAME)
    std::cerr << "game::tiles::set : ressource inconnue (" << type << ")" << std::endl;
  else
    {
      this->ressources[type] = nb;
    }
}
