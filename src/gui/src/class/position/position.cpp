#include <iostream>
#include "position.hpp"

namespace gui
{
  position::position()
  {
    this->pos[0] = 0;
    this->pos[1] = 0;
    this->limit[0] = 0;
    this->limit[1] = 0;
  }

  position::~position()
  { }

  void position::set(double x, double y, double limx, double limy)
  {
    this->pos[0] = x;
    this->pos[1] = y;
    this->limit[0] = limx;
    this->limit[1] = limy; 
  }

  void position::addX(double value)
  {
    double res;
    
    res = pos[0] + value;
    if (res < -1)
      pos[0] = -1;
    else if (res > limit[0])
      pos[0] = limit[0];
    else
      pos[0] = res;
  }

  void position::addY(double value)
  {
    double res;
    
    res = pos[1] + value;
    if (res < -1)
      pos[1] = -1;
    else if (res > limit[1])
      pos[1] = limit[1];
    else
      pos[1] = res;
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
