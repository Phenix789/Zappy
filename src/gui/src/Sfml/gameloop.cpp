#include "sfml.hpp"

bool    sfml::gameloop() const
{
  return (this->run & !(this->data));
}