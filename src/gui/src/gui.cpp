#ifndef DEBUG

#include <iostream>
#include <cstdlib>
#include "interface/network.hpp"
#include "interface/gui.hpp"
#include "parser.hpp"

int	gui::run(game::data &data, INetwork &sock)
{
  parser	pars;
  Igui		*gui;

  data.send_msg("GRAPHIC\n");
  if (network::iteration(data, pars, sock) == false)
    {
      std::cout << "game::run_gui : EXIT_FAILURE" << std::endl;
      return (EXIT_FAILURE);
    }
  gui = create(data);
  gui->init();
  while (gui->is_running() && data.connection)
    {
      if (network::iteration(data, pars, sock) == false)
	{
	  std::cerr << "game::run_gui : connection lost" << std::endl;
	  gui->exit();
	}
      gui->process_event();
      gui->draw_map();
    }
  std::cout << "game::run_gui : EXIT_SUCCESS" << std::endl;
  gui->exit();
  delete gui;
  return (EXIT_SUCCESS);
}

int	gui::main(const std::string host, const std::string port)
{
  game::data	data;
  INetwork	*sock;

  sock.setIp(host);
  sock.setPort(port);
  sock.connect();

  if (!sock)
    res = gui::run(data, *sock);
  else
    {
      std::cout << "Erreur : Impossible de se connecter à un server" << std::endl;
      return (EXIT_FAILURE);
    }
  delete sock;
  return (res);
}

#endif
