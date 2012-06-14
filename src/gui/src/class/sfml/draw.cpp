#include <iostream>
#include <list>
#include "sfml.hpp"

static  game::ress	convertToGame(sfml::sprtype type)
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

static  sfml::sprtype     convertOrientToSpr(game::orientation type)
{
  switch (type)
  {
    case game::NORD:
      return (sfml::SP_CHAR_UP);

    case game::SUD:
      return (sfml::SP_CHAR_DOWN);

    case game::EST:
      return (sfml::SP_CHAR_LEFT);

    case game::OUEST:
      return (sfml::SP_CHAR_RIGHT);

    default:
      throw gui::except("convertOrientToSpr");
  }
}


void    sfml::draw_map()
{
  this->drawBackground();
  this->drawTiles();
  this->drawGui();
  this->App.Display();
#ifdef SHOW_FPS
  std::cout << 1.f / App.GetFrameTime() << std::endl;
#endif
}


void    sfml::drawBackground()
{
  App.Clear();
}

void    sfml::drawGui()
{
  int     i = 0;
  
  App.Draw(getSprite(SP_GUI));
  while (i < 7)
    {
      getSprite(static_cast<sprtype>(i + SP_FOOD)).SetPosition(WIDTH + 16, 377 + i * 41);
      App.Draw(getSprite(static_cast<sprtype>(i + SP_FOOD)));
      i++;
    }
}

void    sfml::drawTiles()
{
  sf::Sprite	&grass(getSprite(SP_GRASS));
  int	posx = (this->pos.getX() > 0 ? this->pos.getX() : 0);
  int	posy = (this->pos.getY() > 0 ? this->pos.getY() : 0);

  for (int y = posy; y < 1 + posy + (HEIGHT / 64) && y < this->data.map.size_y; y++)
    for (int x = posx; x < 1 + posx + (WIDTH / 64) && x < this->data.map.size_x; x++)
      {
	grass.SetPosition((x - pos.getX()) * 64 , (y - pos.getY()) * 64);
	App.Draw(grass);
	drawRessources(x, y);
	drawPlayer(x, y);
      }
}

void	sfml::drawRessources(int x, int y)
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

void    sfml::drawPlayer(int x, int y)
{
  std::list<game::player>::iterator	it;

  it = this->data.map._players.begin();
  while (it != this->data.map._players.end())
    {
      if (it->isHere(x, y))
	{
	  sf::Sprite      &chara(getSprite(convertOrientToSpr(it->orient)));

	  chara.SetPosition((x - pos.getX()) * 64 + 16, (y - pos.getY()) * 64 + 8);
	  App.Draw(chara);
	}
      it++;
    }
}
