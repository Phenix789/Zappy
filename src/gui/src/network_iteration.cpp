#include "interface/network.hpp"
#include "game.hpp"
#include "parser.hpp"

namespace network
{
  bool	iteration(game::data &data, INetwork &sock, parser &pars)
  {
    std::string	buffer;

    if (!sock == false)
      return (false);
    if (sock.isReady(INetwork::WRITE))
      sock.send(data.ask);
    if (sock.isReady(INetwork::READ))
      sock.receive(buffer);
    pars.parse(buffer);
    pars.interpret(data);
    return (true);
  }
};
