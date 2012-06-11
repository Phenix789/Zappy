#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include "interface/gui.hpp"
#include "game.hpp"
#include "position.hpp"

class sfml : public Igui
{
  enum imtype
  {
      INTRO,
      SCORE,
      CHARACTER,
      STONES,
      EGG,
      BACKGROUND    
  };
  
public:
  sfml(game::data &data);
  ~sfml();

public:
  bool	init();
  void	intro();
  bool	is_running() const;
  void	process_event();
  void	draw_map();
  void	wait(int millisecond, bool draw = false);
  void	end();
  void	exit();

private:
  bool				run;
  std::vector<sf::Image>	img;
  sf::RenderWindow		App;
  sf::Event			event;
  game::data			&data;
  gui::position			pos;

private:
  gui::position		&getPos();
  const sf::Image 	&getImg(imtype image);
  void	      		LoadImage();

private:
  void        	draw_background();
  void        	draw_gui();
  void        	draw_info();
  void        	draw_case();
  void        	draw_player();
  void		clear();
  void		close();

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __SFML_HPP_ */
