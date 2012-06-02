#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "parser.hpp"

static boost::smatch                         match;
static boost::regex                          expre;

#define	atom(num) std::atoi(std::string(match[num].first, match[num].second).c_str())

namespace pfunc
{
  static void	cerr_invalid(const std::string &cmd)
  { std::cerr << "Commande invalide : " << cmd << std::endl; }

  void	fpmsz(game::data &data, const std::string &cmd)
  {
    int	x;
    int	y;

    expre = "^msz ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	y = atom(1);
	x = atom(2);
	std::cout << cmd << std::endl;
	data.map.setDim(x, y);
      }
    else
      cerr_invalid(cmd);
  }

  void	fpbct(game::data &data, const std::string &cmd)
  {
    int x;
    int	y;

    expre = "^bct ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	std::cout << cmd << std::endl;
	data.map.set_ress(x, y, game::NOURRITURE, atom(3));
	data.map.set_ress(x, y, game::LINEMATE, atom(4));
	data.map.set_ress(x, y, game::DERAUMATRE, atom(5));
	data.map.set_ress(x, y, game::SIBUR, atom(6));
	data.map.set_ress(x, y, game::MENDIANE, atom(7));
	data.map.set_ress(x, y, game::PHIRAS, atom(8));
	data.map.set_ress(x, y, game::THYSTAME, atom(9));
      }
    else
      cerr_invalid(cmd);
  }
  /*
    void	fptna(game::data &data, const std::string &cmd)
    {
    }
  */
  void	fppnw(game::data &data, const std::string &cmd)
  {
    expre = "^pnw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([]?)$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << cmd << std::endl;
	data.map.add_player(atom(1), atom(2), atom(3), (game::orientation)(atom(4)));
      }
  }
  /*
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
  */
};
