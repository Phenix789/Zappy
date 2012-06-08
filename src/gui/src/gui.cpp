#include <boost/thread.hpp>
#include <iostream>
#include <cstdlib>
#include "game.hpp"
#include "network.hpp"
#include "IGui.hpp"
#include "parser.hpp"

int	game::run_gui(data &data, Network &sock)
{
  data.connection = true;

  {
    Igui	*gui;

    gui = create(data);
    gui->init();
    gui->intro();
    while (gui->is_running() && data.connection)
      {
	gui->process_event();
	gui->draw_map();
	boost::this_thread::sleep(boost::posix_time::milliseconds(50));
      }
    gui->end();
    gui->exit();
    delete gui;
  }
  return (EXIT_SUCCESS);
}

/*
int	game::run_gui(data &data, Network &sock)
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
*/
