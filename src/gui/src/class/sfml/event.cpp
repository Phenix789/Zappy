#include "sfml.hpp"

void    sfml::process_event()
{
  while (App.GetEvent(this->event))
    {
      if (this->event.Type == sf::Event::KeyPressed)
	{
          switch (this->event.Key.Code)
            {
            case sf::Key::Escape:
              this->close();
              return;

            case sf::Key::F1:
	      {
		sf::Image Screen = App.Capture();
		Screen.SaveToFile("screenshot.jpg");
		break;
	      }

	    case sf::Key::Up:
	      getPos().addY(-0.5);
	      this->data.needRedraw(true);
	      break;
	      
	    case sf::Key::Down:
	      getPos().addY(0.5);
	      this->data.needRedraw(true);
	      break;
	      
	    case sf::Key::Left:
	      getPos().addX(-0.5);
	      this->data.needRedraw(true);
	      break;
	      
	    case sf::Key::Right:
	      getPos().addX(0.5);
	      this->data.needRedraw(true);
	      break;
	      
            default:
              break;
            }
	}
	else if (this->event.Type == sf::Event::Resized)
	  this->data.needRedraw(true);
	else if (this->event.Type == sf::Event::Closed)
	{
	  this->close();
	  return;
	}	  
    }
}
