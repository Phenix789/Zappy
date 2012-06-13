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
      GRASS,
      BACKGROUND
  };

  enum config
  {
    WIDTH	= 640,
    HEIGHT	= 640,
    LIMFPS	= 30
  };
  
public:
  sfml(game::data &data);
  ~sfml();

public:
  bool	init();
  void	intro();
  bool	gameloop() const;
  void	process_event();
  void	draw_map();
  void	wait(int millisecond);
  void	end();
  void	exit();

private:
  bool				run;
  std::vector<sf::Image>	img;
  sf::RenderWindow		App;
  game::data			&data;
  gui::position			pos;

private:
  gui::position		&getPos();
  const sf::Image 	&getImg(imtype image);
  void	      		LoadImage();
  void			close();
  
private:
  void        	draw_background();
  void        	draw_case();
  void        	draw_player();
  void        	draw_gui();
  inline void	process_keyboard(sf::Event &event);

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __SFML_HPP_ */
