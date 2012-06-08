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
  void	fpmsz(game::data __attribute__((unused))&data, const std::string &cmd)
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

  void	fpbct(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int	x;
    int	y;

    expre = "^bct ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+) ([0-9]+)$";
    if (boost::regex_search(cmd, match, expre));
  }

  void	fptna(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppnw(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fpppo(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fpplv(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppin(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppex(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppbc(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppic(game::data __attribute__((unused))&data, const std::string &cmd)
  {
  }

  void	fppie(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		x;
    int		y;
    int		result;

    expre = "^pie ([0-9]+) ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	x = std::atoi(std::string(match[1].first, match[1].second).c_str());
	y = std::atoi(std::string(match[1].first, match[1].second).c_str());
	result = std::atoi(std::string(match[1].first, match[1].second).c_str());
	std::cout  << "Fin de l'incantation sur la case " << x << "/" << y << " (Resultat = " << result << ")" << std::endl;
  }

  void	fppfk(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;

    expre = "^pfk ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = std::atoi(std::string(match[1].first, match[1].second).c_str());
	std::cout << "Le joueur #" << joueur << "pond un oeuf." << std::endl;
      }
  }

  void	fppdr(game::data __attribute__((unused))&data, const std::string &cmd)
  {
    int		joueur;
    int		ress;

    expre = "^pdr ([0-9]+) ([0-9]+)";
    if (boost::regex_search(cmd, match, expre))
      {
	joueur = std::atoi(std::string(match[1].first, match[1].second).c_str());
        ress = std::atoi(std::string(match[2].first, match[2].second).c_str());
	std::cout << "Le joueur #" << joueur << " jette une ressource." << std::endl; //(Afficher le type de la ressource)
# warning "Changement sur la map"
      }

    void	fppgt(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      int		joueur;
      int		ress;

      expre = "^pgt ([0-9]+) ([0-9]+)";
      if (boost::regex_search(cmd, match, expre))
	{
	  joueur = std::atoi(std::string(match[1].first, match[1].second).c_str());
	  ress = std::atoi(std::string(match[2].first, match[2].second).c_str());
	  std::cout << "Le joueur #" << joueur << " prend une ressource." << std::endl; // (Afficher le type de la ressource)
#warning "Changement sur la map"
	}
    }

    void	fppdi(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      int		joueur;

      expre = "^pdi ([0-9]+)";
      if (boost::regex_search(cmd, match, expre))
	{
	  joueur = std::atoi(std::string(match[1].first, match[1].second).c_str());
	  std::cout << "Le joueur #" << joueur << " est mort de faim." << std::endl;
	}
    }

    void	fpenw(game::data __attribute__((unused))&data, const std::string &cmd)
    {

    }

    void	fpeht(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      int		oeuf;

      expre = "^eht ([0-9]+)";
      if (boost::regex_search(cmd, match, expre))
	{
	  oeuf = std::atoi(std::string(match[1].first, match[1].second).c_str());
	  std::cout << "L'oeuf #" << oeuf << " a éclot." << std::endl;
	}
    }

    void	fpebo(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      int		oeuf;

      expre = "^ebo ([0-9]+)";
      if (boost::regex_search(cmd, match, expre))
	{
	  oeuf = std::atoi(std::string(match[1].first, match[1].second).c_str());
	  std::cout << "Un joueur s'est connecté pour l'oeuf #" << oeuf << "." << std::endl;
	}
    }

    void	fpedi(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      int		oeuf;

      expre = "^edi ([0-9]+)";
      if (boost::regex_search(cmd, match, expre))
	{
	  // Not implemented
	  oeuf = std::atoi(std::string(match[1].first, match[1].second).c_str());
	  std::cout << "L'oeuf éclos #" << oeuf << " est mort de faim." << std::endl;
	}
    }

    void	fpsgt(game::data __attribute__((unused))&data, const std::string &cmd)
    {
    }

    void	fpseg(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      expre = "^seg";

      if (boost::regex_search(cmd, match, expre))
	{
	  std::cout << "Fin du jeu. Victoire de l'équipe : " << cmd.substr(3) << std::endl;
	}
    }

    void	fpsmg(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      expre = "^smg";

      if (boost::regex_search(cmd, match, expre))
	{
	  std::cout << "Message du server : " << cmd.substr(3) << std::endl;
	}
    }

    void	fpsuc(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      expre = "^suc";

      if (boost::regex_search(cmd, match, expre))
	{
	  std::cerr << "Le server à reçu une commande inconnue" << std::endl;
	}
    }

    void	fpsbp(game::data __attribute__((unused))&data, const std::string &cmd)
    {
      expre = "^sbp";
      if (boost::regex_search(cmd, match, expre))
	{
	  std::cerr << "Le server à reçu une commande invalide (bad parameters) : " << cmd.substr(3) << std::endl;
	}
    }
  };
