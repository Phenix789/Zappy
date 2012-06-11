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
  bool	error = false;

  while (img_name[i] != NULL)
    i++;
  this->img.resize(i);
  while (img_name[i] != NULL)
    {
      if (!this->img[i].LoadFromFile(img_name[i]))
	error = true;
      i++;
    }
  if (error)
  {
    //throw gui::except("Phase de chargement des images"); 
  }
}

