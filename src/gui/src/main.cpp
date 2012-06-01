#include <iostream>
#include <cstdlib>
#include "network.hpp"
#include "game.hpp"

int	main_gui(const std::string host, const std::string port)
{
  game::data	data;
  Network	sock(host, port);

  if (sock.is_connect() == false)
    {
      std::cout << "Erreur Network : Impossible de se connecter" << std::endl;
      return (EXIT_FAILURE);
    }
  return (game::run_gui(data, sock));
}

int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  if (ac == 3)
    return (main_gui(av[1], av[2]));
  std::cout << "Usage : " << av[0] << " [host] [port]" << std::endl;
  return (main_gui("127.0.0.1", "4242"));
  return (EXIT_FAILURE);
}
