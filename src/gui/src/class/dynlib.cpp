#include "sfml.hpp"
#include "gui.hpp"

extern "C" Igui	*create(const game::map &map)
{
  return (new sfml(map));
}
