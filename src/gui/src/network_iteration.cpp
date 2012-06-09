#include <interface/network.hpp"
#include "game.hpp"

namespace network
{
  bool	iteration(game::data &data, INetwork &sock, parser &pars)
  {
    std::string	buffer;

    if (!sock == false)
      return (false);
    if (sock.isReady(WRITE))
      sock.send(data.ask);
    if (sock.isReady(READ))
      sock.receive(buffer);
    pars.parse(buffer);
    pars.interpret(data);
    return (true);
  }
};
