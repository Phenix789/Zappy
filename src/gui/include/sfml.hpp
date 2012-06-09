#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
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
  void	wait(int millisecond);
  void	end();
  void	exit();

private:
  bool				run;
  std::vector<sf::Image>	img;
  sf::RenderWindow		App;
  sf::Event			event;
  game::data			&data;

private:
  void	      load_img();
  void	      close();
  void	      clear();
  void        draw_background();
  void        draw_gui();
  void        draw_info();
  void        draw_case();
  void        draw_player();

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __SFML_HPP_ */
