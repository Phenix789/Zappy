#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "parser.hpp"

static boost::smatch                         match;
static boost::regex                          expre;

namespace pfunc
{
  void	fpmsz(game::data &data, const std::string &cmd)
  {
    int	x;
    int	y;

    expre = "^msz ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	y = std::atoi(std::string(match[1].first, match[1].second).c_str());
	x = std::atoi(std::string(match[2].first, match[2].second).c_str());
	std::cout << "Command : msz " << x << " " << y << std::endl;
	data.map.setDim(x, y);
      }
    else
      std::cerr << "Invalid Command : " << cmd << std::endl;
  }

  void	fpbct(game::data &data, const std::string &cmd)
  {
    int	x;
    int	y;

    expre = "^bct ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre));
  }

  void	fptna(game::data &data, const std::string &cmd)
  {
  }

  void	fppnw(game::data &data, const std::string &cmd)
  {
  }

  void	fpppo(game::data &data, const std::string &cmd)
  {
  }

  void	fpplv(game::data &data, const std::string &cmd)
  {
  }

  void	fppin(game::data &data, const std::string &cmd)
  {
  }

  void	fppex(game::data &data, const std::string &cmd)
  {
  }

  void	fppbc(game::data &data, const std::string &cmd)
  {
  }

  void	fppic(game::data &data, const std::string &cmd)
  {
  }

  void	fppie(game::data &data, const std::string &cmd)
  {
  }

  void	fppfk(game::data &data, const std::string &cmd)
  {
  }

  void	fppdr(game::data &data, const std::string &cmd)
  {
  }

  void	fppgt(game::data &data, const std::string &cmd)
  {
  }

  void	fppdi(game::data &data, const std::string &cmd)
  {
  }

  void	fpenw(game::data &data, const std::string &cmd)
  {
  }

  void	fpeht(game::data &data, const std::string &cmd)
  {
  }

  void	fpebo(game::data &data, const std::string &cmd)
  {
  }

  void	fpedi(game::data &data, const std::string &cmd)
  {
  }

  void	fpsgt(game::data &data, const std::string &cmd)
  {
  }

  void	fpseg(game::data &data, const std::string &cmd)
  {
  }

  void	fpsmg(game::data &data, const std::string &cmd)
  {
  }

  void	fpsuc(game::data &data, const std::string &cmd)
  {
  }

  void	fpsbp(game::data &data, const std::string &cmd)
  {
  }
};
