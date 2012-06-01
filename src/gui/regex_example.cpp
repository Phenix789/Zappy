#include <iostream>
#include <string>
#include <boost/regex.hpp>

int main (int argc, char *argv[])
{
  if (argc > 1)
    {
      std::string url = argv[1];

      boost::regex exp("^A([0-9]+) B([0-9]+)");
      boost::smatch match;
      if (boost::regex_search(url, match, exp))
	{
	  std::cout << std::string(match[1].first, match[1].second) << std::endl;
	  std::cout << std::string(match[2].first, match[2].second) << std::endl;
	}
      else
	std::cout << "No match" << std::endl;
    }
}
