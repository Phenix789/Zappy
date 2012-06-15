#ifndef _GUI_HPP_
#define _GUI_HPP_

/*
** Interface Igui pour charger une bibliothèque graphique dynamiquement (si possible)
** Peut lancer des except (exception avec un msg pour quitter)
** void	wait(int millisecond) : Attend x ms, et gère les inputs / rafraichit l'écran pendant ce temps
** le booleen permet de ne PAS dessiner l'interface
*/
#include <exception>
#include "interface/Inetwork.hpp"
#include "game.hpp"

namespace gui
{
  class except : public std::exception
  {
  public:
    except(const std::string &str) throw();
    ~except() throw();
    const char *what() const throw();

  private:
    const std::string msg;

  private:
    except();
  };

  int   run(game::data &data, INetwork &sock);
  int   main(const std::string addr, const std::string port);
};

#endif /* _GUI_HPP_ */

