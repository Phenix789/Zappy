#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Window.hpp>
#include "map.hpp"
#include "Igui.hpp"

class sfml : public Igui
{
public:
  sfml(const game::map &map);
  ~sfml();

public:
  bool	init();
  void	intro();
  bool	is_running();
  void	process_event();
  void	draw_map();
  void	end();
  void	exit();

private:
  bool			run;
  sf::Window		App;
  sf::Event		event;
  const game::map	&map;

private:
  void        draw_background();
  void        draw_gui();
  void        draw_info();
  void        draw_case();
  void        draw_player();

private:
  sfml();
};

#endif /* __SFML_HPP_ */
