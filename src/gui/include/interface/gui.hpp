#ifndef __IGUI_HPP_
#define __IGUI_HPP_

/*
** Interface Igui pour charger une bibliothèque graphique dynamiquement (si possible)
** Peut lancer des ex_exit (exception avec un msg pour quitter)
** void	wait(int millisecond) : Attend x ms, et gère les inputs / rafraichit l'écran pendant ce temps
** le booleen permet de ne PAS dessiner l'interface
*/
#include <exception>
#include "interface/network.hpp"
#include "game.hpp"

class Igui
{
public:
  virtual ~Igui() {};

  virtual bool  init() = 0;
  virtual void	intro() = 0;
  virtual void	process_event() = 0;
  virtual bool	is_running() const = 0;
  virtual void  draw_map() = 0;
  virtual void  wait(int millisecond, bool draw) = 0;
  virtual void	end() = 0;
  virtual void  exit() = 0;
};

namespace gui
{
  class ex_exit : public std::exception
  {
  public:
    ex_exit(const std::string &str) throw();
    ~ex_exit() throw();
    const char *what() const throw();

  private:
    const std::string msg;

  private:
    ex_exit();
  };

  int			run(game::data &data, INetwork &sock);
  int			main(const std::string addr, const std::string port);
};

extern "C" Igui	*gui_create(game::data &data);

#endif /* __IGUI_HPP_ */
