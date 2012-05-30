/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 02:23:59 2012 quentin duval
// Last update Wed May 30 15:04:21 2012 Alexandre Frizac
*/

#include <cstdlib>
#include <boost/asio.hpp>

int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  std::string				str;
  boost::asio::ip::tcp::iostream	stream("localhost", "6667");

  if (!stream)
    {
      std::cerr << "fail" << std::endl;
      return (EXIT_FAILURE);
    }

  getline(stream, str);
  std::cout << str << std::endl << std::endl;
  getline(stream, str);
  std::cout << str << std::endl;
  std::cout << "Réussite" << std::endl;
  stream.close();
  return (EXIT_SUCCESS);
}
