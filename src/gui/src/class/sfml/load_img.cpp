#include "sfml.hpp"

static const char	*img_name[] =
  {
    "ressources/intro.jpg",
    "ressources/score.jpg",
    "ressources/character.bmp",
    "ressources/stones.bmp",
    "ressources/egg.bmp",
    "ressources/background.bmp",
    NULL
  };

#ifndef DEBUG
#warning "Devrait lancer des exceptions"
#endif
  
void	sfml::load_img(void)
{
  int	i = 0;
  int	max = 0;

  while (img_name[max] != NULL)
    max++;
  this->img.resize(max);
  while (i < max)
    {
      if (!this->img[i].LoadFromFile(img_name[i]))
	{
	  //	throw gui::except("Phase de chargement des images");
	}
      i++;
    }
}

