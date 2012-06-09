#include "interface/gui.hpp"
#include "sfml.hpp"

namespace gui
{
  ex_exit::ex_exit(const std::string &str)  throw() : msg(str)
  {}

  ex_exit::~ex_exit() throw()
  {}

  const char *ex_exit::what() const throw()
  {
    return (this->msg.c_str());
  }
};

extern "C" Igui	*gui_create(game::data &data)
{
  return (new sfml(data));
}
