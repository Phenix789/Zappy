#include <iostream>
#include <cstdlib>
#include "sfml.hpp"
#include "gui.hpp"
#include "parser.hpp"
#include "network.hpp"

int     gui::run(game::data &data, INetwork &sock)
{
  sfml          window(data);
  parser        parse;

  try
    {
      network::init(sock, data, parse);
      window.init();
      window.intro();
      while (window.gameloop())
        {
          network::iteration(sock, data, parse);
          window.process_event();
          window.draw_map();
        }
      window.end();
      window.exit();
    }

  catch (const gui::except &ex)
    {
      std::cout << "Fermeture de l'interface graphique - " << ex.what() << std::endl;
    }

  catch (const network::except &ex)
    {
      std::cout << "Perte de la connexion - " << ex.what() << std::endl;
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

  /* ------------------------------------------- */

int     gui::main(const std::string host, const std::string port)
{
  game::data    data;
  INetwork    *sock = network::create();
  int         res;

  sock->setIp(host);
  sock->setPort(port);
  res = gui::run(data, *sock);

  delete sock;
  return (res);
}
