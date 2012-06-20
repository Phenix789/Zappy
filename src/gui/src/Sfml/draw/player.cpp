#include "sfml.hpp"

void    sfml::drawPlayer(int x, int y)
{
  std::list<game::player>::iterator     it;

  it = this->data.map._players.begin();
  while (it != this->data.map._players.end())
    {
      if (it->isHere(x, y))
        {
	  sf::Sprite		&player = sprite[OrientationToSprite(it->orient)];
	  
	  switch (it->orient)
	  {
	    case game::NORD:
	      player.SetPosition((x - data.pos.getX()) * 64 + 16, (y - data.pos.getY()) * 64 + 8 - 16);
	      break;
	      
	    case game::OUEST:
	      player.SetPosition((x - data.pos.getX()) * 64 + 16 + 16, (y - data.pos.getY()) * 64 + 8);
	      break;
	      
	    case game::SUD:
	      player.SetPosition((x - data.pos.getX()) * 64 + 16, (y - data.pos.getY()) * 64 + 8 + 16);
	      break;
	    case game::EST:
	      player.SetPosition((x - data.pos.getX()) * 64 + 16 - 16, (y - data.pos.getY()) * 64 + 8);
	      break;

	    default:
	      throw gui::except("Bad Orientation - sfml::drawPlayer");
	  }
          App.Draw(player);
        }
      it++;
    }
}