#include <vector>
#include <map>
#include "sfml.hpp"

static const char	*filename[] =
  {
    "ressources/intro.jpg",
    "ressources/score.jpg",
    "ressources/Characters.png",
    "ressources/stones.png",
    "ressources/egg.bmp",
    "ressources/tiles.png",
    "ressources/gui.png",
    "ressources/White_square.png",
    NULL
  };

void	sfml::LoadImage(void)
{
  int	i = 0;
  bool	error = false;

  while (filename[i++] != NULL);
  this->image.resize(i);
  i = 0;
  while (filename[i] != NULL)
    {      
      if (this->image[i].LoadFromFile(filename[i]) == false)
	error = true;
      i++;
    }
  if (error)
    throw gui::except("Phase de chargement des images");
}

void	sfml::SpriteLoad(sprtype type, int left, int up, int right, int down)
 {
   sprite[type].SetImage(getImage(type));
   sprite[type].SetSubRect(sf::Rect<int>(left, up, right, down));
 }

void	sfml::LoadAllSprite(void)
{
  sprite[SP_GRASS].SetImage(getImage(SP_GRASS));
  SpriteLoad(SP_FOOD,           0, 0, 16, 16);
  SpriteLoad(SP_LINEMATE,       16, 0, 32, 16);
  SpriteLoad(SP_DERAUMATRE,     32, 0, 48, 16);
  SpriteLoad(SP_SIBUR,          48, 0, 64, 16);
  SpriteLoad(SP_MENDIANE,       64, 0, 80, 16);
  SpriteLoad(SP_PHIRAS,         80, 0, 96, 16);
  SpriteLoad(SP_THYSTAME,       96, 0, 112, 16);
  sprite[SP_WHITE_SQUARE].SetImage(getImage(SP_WHITE_SQUARE));
  sprite[SP_WHITE_SQUARE].SetCenter(2, 2);
  SpriteLoad(SP_GUI,            0, 0, 200, 800);
  sprite[SP_GUI].SetImage(getImage(SP_GUI));
  sprite[SP_GUI].SetPosition(WIDTH, 0);
  sprite[SP_INTRO].SetImage(getImage(SP_INTRO));
  sprite[SP_INTRO].Resize(WIDTH + GUI_WIDTH, HEIGHT);

  SpriteLoad(SP_CHAR_DOWN,      93, 0, 31 * 4, 49 * 1);
  SpriteLoad(SP_CHAR_LEFT,      93, 49 * 1, 31 * 4, 49 * 2);
  SpriteLoad(SP_CHAR_RIGHT,     93 + 1, 49 * 2, 31 * 4, 49 * 3);
  SpriteLoad(SP_CHAR_UP,        93, 49 * 3, 31 * 4, 49 * 4 - 3);
  
}

const sf::Image	        &sfml::getImage(sprtype type) const
{
  switch (type)
  {
    case SP_WHITE_SQUARE:
      return (image[7]);
    
    case SP_INTRO:
      return (image[0]);
    
    case SP_GRASS:
      return (image[5]);
      
    case SP_FOOD:
    case SP_LINEMATE:
    case SP_DERAUMATRE:
    case SP_SIBUR:
    case SP_MENDIANE:
    case SP_PHIRAS:
    case SP_THYSTAME:
      return (image[3]);
      
    case SP_CHAR_UP:
    case SP_CHAR_LEFT:
    case SP_CHAR_DOWN:
    case SP_CHAR_RIGHT:
      return (image[2]);
      
    case SP_EGG:
      return (image[4]);

    case SP_GUI:
      return (image[6]);
      
    default:
      throw gui::except("sfml::getImage - Bad number");
  } 
}