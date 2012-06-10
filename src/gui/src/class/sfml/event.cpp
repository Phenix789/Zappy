#include "sfml.hpp"

void    sfml::process_event()
{
  while (App.GetEvent(this->event))
    {
      if (this->event.Type == sf::Event::Closed)
	this->close();
      else if (this->event.Type == sf::Event::KeyPressed)
	{
          switch (this->event.Key.Code)
            {
            case sf::Key::Escape:
              this->run = false;
              return;

            case sf::Key::F1:
	      {
		sf::Image Screen = App.Capture();
		Screen.SaveToFile("screenshot.jpg");
		break;
	      }

	    case sf::Key::Up:
	      this->addPosy(0.10);
	      break;
	      
	    case sf::Key::Down:
	      this->addPosy(-0.10);
	      break;
	      
	    case sf::Key::Left:
	      this->addPosx(-0.10);
	      break;
	      
	    case sf::Key::Right:
	      this->addPosx(0.10);
	      break;
	      
            default:
              break;
            }
	}
    }
}
