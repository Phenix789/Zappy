#include <sstream>
#include "sfml.hpp"

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