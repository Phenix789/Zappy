#include <iostream>
#include "position.hpp"

namespace gui
{
  position::position()
  {
    this->pos[0] = 0;
    this->pos[1] = 0;
  }

  position::~position()
  { }

  void position::set(double x, double y)
  {
    this->pos[0] = x;
    this->pos[1] = y;
  }

  void position::addX(double value)
  {
    this->pos[0] += value;
  }

  void position::addY(double value)
  {
    this->pos[1] += value;
  }

  double position::getX(void)
  {
    return (this->pos[0]);
  }

  double position::getY(void)
  {
    return (this->pos[1]);
  }
  
  void	position::dump(void)
  {
    std::cout << pos[0] << "/" << pos[1] <<std::endl;
  }
};
