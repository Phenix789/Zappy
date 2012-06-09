#include "interface/network.hpp"
#include "network/sfml_network.hpp"

namespace network
{
  except::except(const std::string &str) throw() : msg(str)
  {}

  except::~except() throw()
  {}

  const char *except::what() const throw()
  {
    return (this->msg.c_str());
  }
};

extern "C" INetwork	*network_create()
{
  return (new sfNetwork);
}
