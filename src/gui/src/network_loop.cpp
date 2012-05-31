#include <iostream>
#include <list>
#include <string>
#include "network.hpp"
#include "gui.hpp"
#include "game.hpp"
#include "parser.hpp"

bool	game::network_init_data(data_thread &data, network &sock)
{
  data.map.setDim(10, 10);

  return (true);
}

void	game::network_fill_buffer(std::string &str, network &sock)
{
  std::string	buffer;

  while (sock.read_ready())
    {
      if (sock.read(buffer) > 0 && buffer.size() > 0)
	str += buffer;
    }
}

void	game::send_to_server(data_thread &data, network &sock)
{
}

int	game::network_loop(data_thread &data, network &sock)
{
  std::list<std::string>	list;
  std::string	str;

  while (sock.is_connect())
    {
      game::network_fill_buffer(str, sock);
      data.lock();
      if (str.size() > 0)
	{
	  parser::parse_command(str, list);
	  parser::interpret_command(list, data);
	}
      if (data.msg.size() > 0)
	game::send_to_server(data, sock);
      data.unlock();
    }
  sock.disconnect();
  return (EXIT_SUCCESS);
}
