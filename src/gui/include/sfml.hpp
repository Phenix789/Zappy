#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Graphics.hpp>
#include "interface/gui.hpp"
#include "game.hpp"

class sfml : public Igui
{
public:
  sfml(game::data &data);
  ~sfml();

public:
  bool	init();
  void	intro();
  bool	is_running() const;
  void	process_event();
  void	draw_map();
  void	end();
  void	exit();

private:
  bool			run;
  sf::RenderWindow	App;
  sf::Event		event;
  game::data		&data;

private:
  void	      close();
  void	      clear();
  void        draw_background();
  void        draw_gui();
  void        draw_info();
  void        draw_case();
  void        draw_player();

private:
  sfml();
};

#endif /* __SFML_HPP_ */
