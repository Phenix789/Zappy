/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 02:23:59 2012 quentin duval
// Last update Fri Jun  1 01:01:34 2012 Alexandre Frizac
*/

#include "network.hpp"
#include "gui.hpp"
#include "game.hpp"

int	main_gui(const std::string host, const std::string port)
{
  data_thread	data;
  network	sock(host, port);

  if (sock.is_connect() == false)
    {
      std::cout << "Erreur Network : Impossible de se connecter" << std::endl;
      return (EXIT_FAILURE);
    }
  if (game::network_init_data(data, sock) == false)
    return (EXIT_FAILURE);
  //  game::launch_gui(data);
  return (game::network_loop(data, sock));
}


int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  if (ac == 3)
    return (main_gui(av[1], av[2]));
  std::cout << "Usage : " << av[0] << " [host] [port]" << std::endl;
  return (EXIT_FAILURE);
}
