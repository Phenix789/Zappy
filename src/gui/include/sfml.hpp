#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "interface/gui.hpp"
#include "game.hpp"
#include "position.hpp"

class sfml : public Igui
{
private:
  enum config
    {
      GUI_WIDTH         = 200,
      WIDTH             = 800,
      HEIGHT            = 800,
      TILE_BY_WINDOWS	= 12,
    };

public:
  enum sprtype
    {
      SP_GRASS,
      SP_FOOD,
      SP_LINEMATE,
      SP_DERAUMATRE,
      SP_SIBUR,
      SP_MENDIANE,
      SP_PHIRAS,
      SP_THYSTAME,
      SP_CHAR_UP,
      SP_CHAR_LEFT,
      SP_CHAR_DOWN,
      SP_CHAR_RIGHT,
      SP_EGG,
      SP_GUI,
      SP_LAST
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
  sf::RenderWindow		App;
  game::data			&data;
  gui::position			pos;
  std::vector<sf::Image>	image;
  std::vector<sf::Sprite>	sprite;
  bool				run;

private:
  gui::position		&getPos();
  sf::Sprite		&getSprite(sprtype type);
  const sf::Image 	&getImage(sprtype type) const;
  bool			isInWindows(int x, int y) const;
  void	      		LoadImage();
  void			LoadSprite();
  void			Load_ASprite(sprtype type, int left, int up, int right, int down);
  void			close();

private:
  inline void	process_keyboard(sf::Event &event);
  void        	drawBackground();
  void        	drawTiles();
  void		drawRessources(int x, int y);
  void        	drawPlayer(int x, int y);
  void        	drawGui();

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __SFML_HPP_ */
