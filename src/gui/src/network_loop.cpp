#include "network.hpp"
#include "gui.hpp"
#include "game.hpp"

bool	init_data(data_thread &data, network &sock)
{
  data.map.setDim(10, 10);

  return (true);
}

#include <iostream>

int	network_loop(data_thread &data, network &sock)
{
  std::string	buffer;

  while (sock.is_connect())
    {
      if (sock.read_ready())
	if (sock.read(buffer) > 0 && buffer.size() > 0)
	  std::cout << buffer << std::endl;
    }
  sock.disconnect();
  return (EXIT_SUCCESS);
}
