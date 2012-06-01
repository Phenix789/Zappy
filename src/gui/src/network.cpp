#include <cstdlib>
#include <iostream>
#include <list>
#include <string>
#include "network.hpp"
#include "game.hpp"
#include "parser.hpp"

void	network::send_list(std::list<std::string> &list, Network &sock)
{
  while (list.size() > 0)
    {
      sock << list.front();
      list.pop_front();
    }
}

bool	network::iteration(game::data &data, parser &pars, Network &sock)
{
  std::string			str;

  if (sock.is_connect())
    {
      sock >> str;
      if (str.size() > 0)
	{
	  pars.parse(str);
	  pars.interpret(data);
	}
      if (data.msg_to_send())
	network::send_list(data.ask, sock);
      return (true);
    }
  else
    {
      std::cerr << "network::iteration : network down" << std::endl;
      return (false);
    }
}
