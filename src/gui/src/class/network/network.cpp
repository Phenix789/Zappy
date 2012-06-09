#include "interface/network.hpp"
#include "network/sfml_network.hpp"

extern "C" INetwork	*network_create()
{
  return (new sfNetwork);
}
