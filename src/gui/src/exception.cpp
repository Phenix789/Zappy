#include "gui.hpp"
#include "network.hpp"

gui::except::except(const std::string &str)  throw() : msg(str)
{}

gui::except::~except() throw()
{}

const char *gui::except::what() const throw()
{
  return (this->msg.c_str());
}


network::except::except(const std::string &str) throw() : msg(str)
{}

network::except::~except() throw()
{}

const char *network::except::what() const throw()
{
  return (this->msg.c_str());
}

