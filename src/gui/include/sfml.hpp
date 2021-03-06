#ifndef __SFML_HPP_
#define __SFML_HPP_

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <map>
#include "game.hpp"
#include "position.hpp"
#include "gui.hpp"

class sfml
{
private:
  enum config
    {
      GUI_WIDTH         = 200,
      WIDTH             = 800,
      HEIGHT            = 800
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
      SP_INTRO,
      SP_SCORE,
      SP_WHITE_SQUARE,
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
  std::vector<sf::Image>        image;
  std::map<sprtype, sf::Sprite> sprite;
  std::pair<int, int>           gui_focus;
  bool                          run;
  
private:
  void          PosAddX(float value);
  void          PosAddY(float value);
  bool		isInWindows(int x, int y) const;
  void          LoadImage(void);
  void          LoadAllSprite(void);
  
  void		close();
  game::ress    SprtypeToRess(sfml::sprtype type);
  sfml::sprtype OrientationToSprite(game::orientation type);
  
  
private:
  const sf::Image     &getImage(sprtype type) const;
  void          SpriteLoad(sprtype type, int left, int up, int right, int down);
  void	        process_keyboard(sf::Event &event);
  void          process_mouse(sf::Event &event);
  void        	drawBackground();
  void        	drawTiles();
  void		drawRessources(int x, int y);
  void        	drawPlayer(int x, int y);
  void          drawEgg(int x, int y);
  void        	drawGui();
  void          drawGuiText(int i);

private:
  sfml();
  sfml(const sfml &other);
};

#endif /* __SFML_HPP_ */
