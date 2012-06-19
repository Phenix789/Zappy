#include "sfml.hpp"

void    sfml::PosAddX(float value)
{
  float x = data.pos.getX() + value;
  float lim = data.pos.getLimitX() - (sfml::WIDTH / 64.0) + 1;

  data.pos.setX(x > lim ? lim : x);
}

void    sfml::PosAddY(float value)
{
  float y = data.pos.getY() + value;
  float lim = data.pos.getLimitY() - (sfml::HEIGHT / 64.0) + 1;

  data.pos.setY(y > lim ? lim : y);
}