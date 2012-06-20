#include <iostream>
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
  sock.send(data.waitList);
  sock.receive(buffer, 0.030);
  pars.parse(buffer);
  pars.interpret(data);
  #endif
}

void  network::init(__attribute__((unused))INetwork &sock,
                    __attribute__((unused))game::data &data,
                    __attribute__((unused))parser &pars)
{
#ifndef DEBUG_NETWORK
  std::string buffer;
  int         essay = 1;
  bool        status = false;
  
  status = sock.connect();
  while (status != true)
    {
      essay++;
      if (essay > 5)
        throw network::except("Impossible de se connecter au server distant");
      sf::Sleep(2);
      std::cout << essay << " essai - ";
      status = sock.connect();
    }
  sock.receive(buffer, 10);
  pars.parse(buffer);
  if (pars.getFirstString().compare("BIENVENUE") == 0)
    {
      sock.send("GRAPHIC\n");
      data.allowConnection();
      pars.delFirstString();
      sock.send(data.waitList);
      sock.receive(buffer, 10);
      pars.parse(buffer);
      pars.interpret(data);
    }
  else
    throw network::except("Mauvais server");
#else
    data.allowConnection();
#endif
}

extern "C" INetwork     *network::create()
{
  return (new sfNetwork);
}
