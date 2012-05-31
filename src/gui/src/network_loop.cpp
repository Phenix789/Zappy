#include "network.hpp"
#include "gui.hpp"
#include "game.hpp"

bool	init_data(data_thread &data, boost::asio::ip::tcp::iostream &sock)
{
  data.map.setDim(10, 10);

  return (true);
}

int	network_loop(data_thread &data, boost::asio::ip::tcp::iostream &sock)
{
  std::string   buffer;

  while (sock)
    {
      getline(sock, buffer);
      sock << "GRAPHIC\n" << std::flush;
      std::cout << buffer << std::endl;
    }
  sock.close();
  return (EXIT_SUCCESS);
}
