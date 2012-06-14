#include "sfml.hpp"

static const char	*img_name[] =
  {
    "ressources/intro.jpg",
    "ressources/score.jpg",
    "ressources/Characters.png",
    "ressources/stones.png",
    "ressources/egg.bmp",
    "ressources/tiles.png",
    "ressources/gui.png",
    NULL
  };

void	sfml::LoadImage(void)
{
  int	i = 0;
  bool	error = false;

  this->image.resize(7);
  while (img_name[i] != NULL)
    {      
      if (this->image[i].LoadFromFile(img_name[i]) == false)
	error = true;
      i++;
    }
  if (error)
    {
#ifndef DEBUG
      throw gui::except("Phase de chargement des images");
#endif
    }
}

void	sfml::Load_ASprite(sprtype type, int left, int up, int right, int down)
 {
   this->sprite[type].SetImage(getImage(type));
   this->sprite[type].SetSubRect(sf::Rect<int>(left, up, right, down));
 }

// Sprite Character : 31 pixels de large && 49 de haut
// En fait non, pas trop. Ou alors la source est daubée
void	sfml::LoadSprite(void)
{
  this->sprite.resize(SP_LAST);
  this->sprite[SP_GRASS].SetImage(getImage(SP_GRASS));
  Load_ASprite(SP_FOOD, 0, 0, 16, 16);
  Load_ASprite(SP_LINEMATE, 16, 0, 32, 16);
  Load_ASprite(SP_DERAUMATRE, 32, 0, 48, 16);
  Load_ASprite(SP_SIBUR, 48, 0, 64, 16);
  Load_ASprite(SP_MENDIANE, 64, 0, 80, 16);
  Load_ASprite(SP_PHIRAS, 80, 0, 96, 16);
  Load_ASprite(SP_THYSTAME, 96, 0, 112, 16);
  Load_ASprite(SP_CHAR_DOWN, 	93, 0, 	    31 * 4, 49 * 1);
  Load_ASprite(SP_CHAR_LEFT, 	93, 49 * 1, 31 * 4, 49 * 2);
  Load_ASprite(SP_CHAR_RIGHT, 	93 + 1, 49 * 2, 31 * 4, 49 * 3);
  Load_ASprite(SP_CHAR_UP, 	93, 49 * 3, 31 * 4, 49 * 4 - 3);
  sprite[SP_GUI].SetImage(getImage(SP_GUI));
  sprite[SP_GUI].SetPosition(WIDTH, 0);
}

const sf::Image	&sfml::getImage(sprtype type) const
{
  switch (type)
  {
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

sf::Sprite	&sfml::getSprite(sprtype type)
{
  return (sprite[type]);
}