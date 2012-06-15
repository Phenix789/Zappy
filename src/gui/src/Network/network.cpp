#include "network.hpp"
#include "game.hpp"
#include "parser.hpp"
#include "sfml.hpp"

void  network::iteration(__attribute__((unused))INetwork &sock,
                         __attribute__((unused))game::data &data,
                         __attribute__((unused))parser &pars)
{
  #ifndef DEBUG_NETWORK
  std::string buffer;

  if (!sock == false)
    throw network::except("Connection lost");
  if (sock.isReady(INetwork::WRITE))
    sock.send(data.waitList);
  if (sock.isReady(INetwork::READ))
    sock.receive(buffer);
  pars.parse(buffer);
  pars.interpret(data);

  #endif
}

void  network::init(__attribute__((unused))INetwork &sock,
                    __attribute__((unused))game::data &data,
                    __attribute__((unused))parser &pars)
{
  std::string buffer;
  int         essay = 0;

  sock.setBlocking(true);
  while (sock.connect() != sf::Socket::Done)
    {
    if (essay > 0)
      throw network::except("Impossible de se connecter au server distant");
    essay++;
    sf::Sleep(4);
    std::cout << "Tentative de connection numéro " << essay << " ..." << std::endl;
    }
  sock.receive(buffer);
  pars.parse(buffer);
  if (pars.getFirstString().compare("BIENVENUE") == 0)
    {
      sock.send("GRAPHIC\n");
      data.allowConnection();
      pars.delFirstString();
      sock.receive(buffer);
      iteration(sock, data, pars);
      sock.setBlocking(false);
    }
  else
    throw network::except("Mauvais server");
}

extern "C" INetwork     *network::create()
{
  return (new sfNetwork);
}
