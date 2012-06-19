#include <iostream>
#include <sstream>
#include <list>
#include "sfml.hpp"

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
  
  App.Draw(sprite[SP_GUI]);

  while (i < 7)
    {
      sprite[static_cast<sprtype>(i + SP_FOOD)].SetPosition(WIDTH + 16, 377 + i * 41);
      App.Draw(sprite[static_cast<sprtype>(i + SP_FOOD)]);
      drawGuiText(i);
      i++;
    }
}

void    sfml::drawGuiText(int i)
{
  if (gui_focus.first >= 0 && gui_focus.second >= 0)
    {
      game::tiles   tile = data.map.getTile(gui_focus.first, gui_focus.second);
      std::ostringstream    os;
      sf::String    nb;

      os << tile.get(static_cast<game::ress>(i));
      nb.SetColor(sf::Color(0, 0, 0));
      nb.SetText(os.str());
      nb.SetPosition(WIDTH + 16 + 40, 365 + i * 41);
      App.Draw(nb);
    }
}

void    sfml::drawTiles()
{
  int	posx = (data.pos.getX() > 0 ? data.pos.getX() : 0);
  int	posy = (data.pos.getY() > 0 ? data.pos.getY() : 0);
  bool  print_border = false;
  
  for (int y = posy; y < 1 + posy + (HEIGHT / 64) && y < this->data.map.size_y; y++)
    for (int x = posx; x < 1 + posx + (WIDTH / 64) && x < this->data.map.size_x; x++)
      {
	sprite[SP_GRASS].SetPosition((x - data.pos.getX()) * 64 , (y - data.pos.getY()) * 64);
	App.Draw(sprite[SP_GRASS]);
	drawRessources(x, y);
	drawPlayer(x, y);
        if (x == gui_focus.first && y == gui_focus.second)
          {
            print_border = true;
            sprite[SP_WHITE_SQUARE].SetPosition((x - data.pos.getX()) * 64 , (y - data.pos.getY()) * 64);
          }
      }
  if (print_border)
    App.Draw(sprite[SP_WHITE_SQUARE]);
}

void	sfml::drawRessources(int x, int y)
{
  const game::tiles		&tile = this->data.map.getTile(x, y);
  sprtype			i = SP_FOOD;

  while (i <= SP_THYSTAME)
    {
      if (tile.get(SprtypeToRess(i)) > 0)
	{
	  sprite[i].SetPosition((x - data.pos.getX()) * 64 + i * 6, (y - data.pos.getY()) * 64 + i * 6);
	  App.Draw(sprite[i]);
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
	  sprite[OrientationToSprite(it->orient)].SetPosition((x - data.pos.getX()) * 64 + 16, (y - data.pos.getY()) * 64 + 8);
	  App.Draw(sprite[OrientationToSprite(it->orient)]);
	}
      it++;
    }
}
