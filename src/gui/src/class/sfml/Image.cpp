#include "sfml.hpp"

static const char	*img_name[] =
  {
    "ressources/intro.jpg",
    "ressources/score.jpg",
    "ressources/character.bmp",
    "ressources/stones.png",
    "ressources/egg.bmp",
    "ressources/tiles.png",
    NULL
  };

void	sfml::LoadImage(void)
{
  int	i = 0;
  bool	error = false;

  this->image.resize(6);
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

 void	sfml::Load_ARess(sprtype type, int a, int b)
 {
   this->sprite[type].SetImage(getImage(type));
   this->sprite[type].SetSubRect(sf::Rect<int>(a, 0, b, 16));
 }

void	sfml::LoadSprite(void)
{
  this->sprite.resize(SP_LAST);
  this->sprite[SP_GRASS].SetImage(getImage(SP_GRASS));
  Load_ARess(SP_FOOD, 0, 16);
  Load_ARess(SP_LINEMATE, 16, 32);
  Load_ARess(SP_DERAUMATRE, 32, 48);
  Load_ARess(SP_SIBUR, 48, 64);
  Load_ARess(SP_MENDIANE, 64, 80);
  Load_ARess(SP_PHIRAS, 80, 96);
  Load_ARess(SP_THYSTAME, 96, 112);
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
    
    default:
      throw gui::except("sfml::getImage - Bad number");
  } 
}

sf::Sprite	&sfml::getSprite(sprtype type)
{
  return (sprite[type]);
}