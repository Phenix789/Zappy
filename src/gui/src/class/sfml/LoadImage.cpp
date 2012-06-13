#include "sfml.hpp"

static const char	*img_name[] =
  {
    "ressources/intro.jpg",
    "ressources/score.jpg",
    "ressources/character.bmp",
    "ressources/stones.bmp",
    "ressources/egg.bmp",
    "ressources/tiles.png",
    NULL
  };

void	sfml::LoadImage(void)
{
  int	i = 0;
  bool	error = false;

  while (img_name[i++] != NULL);
  this->img.resize(i);
  i = 0;
  while (img_name[i] != NULL)
    {
      if (this->img.at(i).LoadFromFile(img_name[i]) == false)
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

void	sfml::LoadSprite(void)
{
  this->sprite.resize(8);
  this->sprite[0].SetImage(this->getImg(IM_GRASS));
  this->sprite[1].SetImage(this->getImg(IM_STONES));
  this->sprite[1].SetSubRect(sf::Rect<int>(0, 0, 64, 64));
  
}