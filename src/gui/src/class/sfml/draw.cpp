#include "sfml.hpp"

static inline game::ress	convertToGame(sfml::sprtype type)
{
  switch (type)
  {
    case sfml::SP_FOOD:
      return (game::FOOD);
      
    case sfml::SP_LINEMATE:
      return (game::LINEMATE);
      
    case sfml::SP_DERAUMATRE:
      return (game::DERAUMATRE);
      
    case sfml::SP_SIBUR:
      return (game::SIBUR);
      
    case sfml::SP_MENDIANE:
      return (game::MENDIANE);
      
    case sfml::SP_PHIRAS:
      return (game::PHIRAS);
      
    case sfml::SP_THYSTAME:
      return (game::THYSTAME);
      
    default:
      throw gui::except("convertToGame - Bad type");
  }
}

void    sfml::draw_map()
{
  if (this->data.needRedraw())
    {
      this->App.Clear();
      this->drawBackground();
      this->drawTiles();
      this->drawGui();
      this->data.needRedraw(false);
    }
  this->App.Display();
}


void    sfml::drawBackground()
{

}

void    sfml::drawGui() { }

void    sfml::drawTiles()
{
  sf::Sprite	&grass(getSprite(SP_GRASS));
  int	posx = this->pos.getX();
  int	posy = this->pos.getY();

  for (int y = (posy > 0 ? posy : 0); y < 1 + posy + (HEIGHT / 64) && y < this->data.map.size_y; y++)
    for (int x = (posx > 0 ? posx : 0); x < 1 + posx + (WIDTH / 64) && x < this->data.map.size_x; x++)
      {
	grass.SetPosition((x - pos.getX()) * 64 , (y - pos.getY()) * 64);
	App.Draw(grass);
	drawRessources(x, y);
	drawPlayer(x, y);
      }

}

void	sfml::drawRessources(int x, int y)
{
  if (x < 0 || x > this->data.map.size_x)
    return;
  else if (y < 0 || y > this->data.map.size_y)
    return;
  else
    {
      const game::tiles		&tile = this->data.map.getTile(x, y);
      sprtype			i = SP_FOOD;

      while (i <= SP_THYSTAME)
	{
	  if (tile.get(convertToGame(i)) > 0)
	    {
	      getSprite(i).SetPosition((x - pos.getX()) * 64 + i * 6, (y - pos.getY()) * 64 + i * 6);
	      App.Draw(getSprite(i));
	    }
	  i = (sprtype)((int)(i) + 1); // On peut faire pire, je suis sur
	}
    }
}

void    sfml::drawPlayer(int x, int y)
{


}
