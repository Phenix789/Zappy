#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <map>
#include <cstdlib>
#include "parser.hpp"

#define	atom(num) std::atoi(std::string(match[num].first, match[num].second).c_str())

namespace pfunc
{
  static boost::smatch                         match;
  static boost::regex                          expre;

  static inline void PrintError(const std::string &cmd)
  { std::cerr << color::red << "Commande invalide : " << color::white << cmd << std::endl; }

  void	fpmsz(game::data __attribute__((unused))&data, const std::string &cmd)
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
      PrintError(cmd);
  }

  void	fpbct(game::data __attribute__((unused))&data, const std::string &cmd)
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
      PrintError(cmd);
  }

  void	fptna(game::data __attribute__((unused))&data, const std::string &cmd)
  {
# warning "todo"
    if (1);
    else
      PrintError(cmd);
  }

  void	fppnw(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^pnw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([]?)$";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << cmd << std::endl;
	data.map.add_player(atom(1), atom(2), atom(3), (game::orientation)(atom(4)));
      }
    else
      PrintError(cmd);
  }

  void	fpppo(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    int		x;
    int		y;
    int		orientation;

    expre = "^ppo ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	x = atom(2);
	y = atom(3);
	orientation = atom(4);
	std::cout << "Joueur #" << joueur << " est sur la position " << x << "/" << y;
	std::cout << " et est orienté vers " << orientation << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpplv(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    int		level;

    expre = "^plv ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	level = atom(2);
#warning "modif map"
	std::cout << "Le joueur #" << joueur << " est niveau " << level << "." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppin(game::data __attribute__((unused))&data, const std::string &cmd)
  {
#warning "regexp a tester"
    expre = "^plv ([0-9]+){10}$";
    if (boost::regex_search(cmd, match, expre))
      {
#warning "todo (O'really ?)"
      }
    else
      PrintError(cmd);
  }

  void	fppex(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	joueur;

    expre = "^pex ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	std::cout << "Le joueur #" << joueur << " expulse." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppbc(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    std::string	msg;

    expre = "^pbc ([0-9]+) ([.]*)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	msg = std::string(match[2].first, match[2].second);
	std::cout << "Le joueur #" << joueur << " broadcast ce message : " << msg << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppic(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	joueur;
    int	x;
    int	y;
    int	level;

    expre = "^pic ([0-9]) ([0-9]) ([0-9]) ([0-9])";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	level = atom(3);
	joueur = atom(4);
	std::cout << "Le joueur #" << joueur << " lance une incantation de level " << level;
	std::cout << " sur la case " << x << "/" << y << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppie(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		x;
    int		y;
    int		result;

    expre = "^pie ([0-9]+) ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	x = atom(1);
	y = atom(2);
	result = atom(3);
	std::cout << "Fin de l'incantation sur la case " << x << "/" << y;
	std::cout << " (Resultat = " << result << ")." << std::endl;
#warning "Changement sur la map"
      }
    else
      PrintError(cmd);
  }

  void	fppfk(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;

    expre = "^pfk ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	std::cout << "Le joueur #" << joueur << "pond un oeuf." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fppdr(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    int		ress;

    expre = "^pdr ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	ress = atom(2);
	std::cout << "Le joueur #" << joueur << " jette une ressource (" << ress;
	std::cout << ")." << std::endl;
# warning "Changement sur la map"
      }
    else
      PrintError(cmd);
  }

  void	fppgt(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    int		ress;

    expre = "^pgt ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	ress = atom(2);
	std::cout << "Le joueur #" << joueur << " prend une ressource (" << ress;
	std::cout << ress << ")." << std::endl;
#warning "Changement sur la map"
      }
    else
      PrintError(cmd);
  }

  void	fppdi(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;

    expre = "^pdi ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = atom(1);
	std::cout << "Le joueur #" << joueur << " est mort de faim." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpenw(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	oeuf;
    int	joueur;
    int	x;
    int	y;

    expre = "^enw ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre))
      {
	oeuf = atom(1);
	joueur = atom(2);
	x = atom(3);
	y = atom(4);
	std::cout << "L'oeuf #" << oeuf << " a été pondu sur la case " << x << "/" << y;
	std::cout << " par le joueur #" << joueur << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpeht(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		oeuf;

    expre = "^eht ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	oeuf = atom(1);
	std::cout << "L'oeuf #" << oeuf << " a éclot." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpebo(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		oeuf;

    expre = "^ebo ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	oeuf = atom(1);
	std::cout << "Un joueur s'est connecté pour l'oeuf #" << oeuf << "." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpedi(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		oeuf;

    expre = "^edi ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	// Not implemented
	oeuf = atom(1);
	std::cout << "L'oeuf éclos #" << oeuf << " est mort de faim." << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsgt(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    double	tps;

    expre = "^sgt ([0-9.]+)$";
    #warning "work ?"
    if (boost::regex_search(cmd, match, expre))
      {
	tps = std::atof(std::string(match[1].first, match[1].second).c_str());
	std::cout << "L'unité de temps courante est " << tps << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpseg(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^seg";

    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << "Fin du jeu. Victoire de l'équipe : " << cmd.substr(3) << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsmg(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^smg";

    if (boost::regex_search(cmd, match, expre))
      {
	std::cout << "Message du server : " << cmd.substr(3) << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsuc(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^suc";

    if (boost::regex_search(cmd, match, expre))
      {
	std::cerr << "Le server à reçu une commande inconnue" << std::endl;
      }
    else
      PrintError(cmd);
  }

  void	fpsbp(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    expre = "^sbp";
    if (boost::regex_search(cmd, match, expre))
      {
	std::cerr << "Le server à reçu une commande invalide (bad parameters) : ";
	std::cerr << cmd.substr(3) << std::endl;
      }
    else
      PrintError(cmd);
  }
};

namespace color
{
  const char *red =      "\033[00;31m";
  const char *orange =   "\033[00;33m";
  const char *white =    "\033[00m";
}
