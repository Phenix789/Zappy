#include <iostream>
#include "position.hpp"
#include "game.hpp"
#include <sfml.hpp>

namespace gui
{
  position::position()
  {
    this->pos[0] = -1;
    this->pos[1] = -1;
    this->limit[0] = -1;
    this->limit[1] = -1;
  }

  position::~position()
  { }

  void position::setLimit(int x, int y)
  {
    this->pos[0] = -1;
    this->pos[1] = -1;
    this->limit[0] = x;
    this->limit[1] = y;

  }

  void  position::setLimit(game::data &data)
  {
    this->setLimit(data.map.size_x, data.map.size_y);
  }
  
  void position::setX(float value)
  {
    float res;

    res = value;
    if (res < -1)
      pos[0] = -1;
    else if (res > limit[0])
      pos[0] = limit[0];
    else
      pos[0] = res;
  }

  void position::setY(float value)
  {
    float res;

    res = value;
    if (res < -1)
      pos[1] = -1;
    else if (res > limit[1])
      pos[1] = limit[1];
    else
      pos[1] = res;
  }

  float position::getX(void) const
  {
    return (this->pos[0]);
  }

  float position::getY(void) const
  {
    return (this->pos[1]);
  }

  void	position::dump(void)
  {
    std::cout << pos[0] << "/" << pos[1] << " | " << limit[0] << "/" << limit[1] << std::endl;
  }

  float   position::getLimitX(void) const
  {
    return (this->limit[0]);
  }

  float   position::getLimitY(void) const
  {
    return (this->limit[1]);
  }
};
