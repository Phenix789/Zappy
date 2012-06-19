#include "sfml.hpp"

void    sfml::drawRessources(int x, int y)
{
  const game::tiles             &tile = this->data.map.getTile(x, y);
  sprtype                       i = SP_FOOD;

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