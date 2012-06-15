#include "gui.hpp"
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
