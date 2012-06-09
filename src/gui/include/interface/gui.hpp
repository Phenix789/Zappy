#ifndef __IGUI_HPP_
#define __IGUI_HPP_

/*
** Interface Igui pour charger une bibliothèque graphique dynamiquement (si possible)
** Peut lancer des ex_exit (exception avec un msg pour quitter)
** void	wait(int millisecond) : Attend x ms, et gère les inputs / rafraichit l'écran pendant ce temps
*/
#include <exception>
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
  virtual void  wait(int millisecond) = 0;
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

  extern "C" Igui	*create(game::data &data);
};

#endif /* __IGUI_HPP_ */
