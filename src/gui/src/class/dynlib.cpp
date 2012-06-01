#include "IGui.hpp"
#include "sfml.hpp"

extern "C" Igui	*create(game::data &data)
{
  return (new sfml(data));
}
