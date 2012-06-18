#include <iostream>
#include "game.hpp"
#include "gui.hpp"

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
    this->ressources[type] = nb;
}

int	game::tiles::get(ress type) const
{
  if (type < FOOD || type > THYSTAME)
  {
    std::cerr << "game::tiles::set : ressource inconnue (" << type << ")" << std::endl;
    throw gui::except("game::tiles::get exception");
  }
  return (this->ressources[type]);
}

void    game::tiles::dump() const
{
  std::cout << "Tiles : " << ressources[0] << "/" << ressources[1] << "/" << ressources[2] << "/" << ressources[3] << "/" << ressources[4] << "/" << ressources[5] << "/";
  std::cout << ressources[6] << std::endl;
}