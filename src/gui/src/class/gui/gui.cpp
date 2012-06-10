#include "interface/gui.hpp"
#include "sfml.hpp"

namespace gui
{
  except::except(const std::string &str)  throw() : msg(str)
  {}

  except::~except() throw()
  {}

  const char *except::what() const throw()
  {
    return (this->msg.c_str());
  }
};

extern "C" Igui	*gui_create(game::data &data)
{
  return (new sfml(data));
}
