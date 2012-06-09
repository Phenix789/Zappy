#include "sfml.hpp"

static const char	*img_name[] =
  {
    "ressources/intro.bmp",
    "ressources/score.bmp",
    "ressources/character.bmp",
    "ressources/stones.bmp",
    "ressources/egg.bmp",
    "ressources/background.bmp",
    NULL
  };

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
	throw gui::ex_exit("Phase de chargement des images");
      i++;
    }
}
