/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 02:23:59 2012 quentin duval
// Last update Thu May 31 18:44:00 2012 Alexandre Frizac
*/

#include "gui.hpp"
#include "network.hpp"

#include <unistd.h>

int	main_gui(const std::string host, const std::string port)
{
  data_thread	data;
  network	sock(host, port);

  if (!sock)
    {
      std::cout << "Erreur Network : Impossible de se connecter" << std::endl;
      return (EXIT_FAILURE);
    }
  /*
  if (init_data(data) == false)
    return (EXIT_FAILURE);
  game::launch_gui(data);
  return (boucle_network(data));
  */
  std::string	buffer;
  //  while (sock)
  {
    buffer.clear();
    getline(sock, buffer);
    sock << "GRAPHIC\n" << std::flush;
    std::cout << buffer << std::endl;
  }
  sock.close();
  return (EXIT_SUCCESS);
}


int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  if (ac == 3)
    return (main_gui(av[1], av[2]));
  std::cout << "Usage : " << av[0] << " [host] [port]" << std::endl;
  return (EXIT_FAILURE);
}

/*
data_thread data;
game::launch_gui(data);
*/
