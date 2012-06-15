#include "sfml.hpp"

bool	sfml::isInWindows(int x, int y) const
{
  if (x < this->pos.getX() || y < this->pos.getY())
    return (false);
  else if (x > this->pos.getX() + TILE_BY_WINDOWS)
    return (false);
  else if (y > this->pos.getY() + TILE_BY_WINDOWS)
    return (false);
  return (true);
};