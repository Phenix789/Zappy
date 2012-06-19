#include "sfml.hpp"

void    sfml::drawPlayer(int x, int y)
{
  std::list<game::player>::iterator     it;

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