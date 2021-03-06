#include <iostream>
#include "game.hpp"

namespace game
{
  player::player(int x, int y, int num, orientation ori) : number(num)
  { this->set(x, y, ori); }

  player::~player()
  { }

  void	player::set(int x, int y, orientation ori)
  {
    if (ori < NORD || ori > OUEST)
      std::cerr << "game::player::set : orientation invalide " << ori << std::endl;
    else
      {
	this->pos_x = x;
	this->pos_y = y;
	this->orient = ori;
      }
  }

   bool player::isHere(int x, int y) const
   {
      if (this->pos_x == x && this->pos_y == y)
        return (true);
      return (false);
   }
};
