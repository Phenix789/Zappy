#include <boost/regex.hpp>
#include <iostream>
#include <sstream>
#include "parser.hpp"

parser::parser()
{
  this->func["msz"] = &pfunc::fpmsz;
}

parser::~parser()
{ }

void	parser::parse(std::string &str)
{
  std::istringstream    input(str);
  std::string           buffer;

  while (input)
    {
      buffer.clear();
      getline(input, buffer);
      if (buffer.size() > 0)
        {
          this->list.push_back(buffer);
	  std::cout << "Receive : " << buffer << std::endl;
        }
    }
}

bool    parser::interpret(game::data &data)
{
  boost::regex	msz("msz [0-9]* [0-9]*");
  boost::cmatch	what;

  if (this->list.front().compare("BIENVENUE") == 0)
    {
      data.allowConnection();
      this->list.pop_front();
    }
  if (this->list.size() == 0)
    return (true);
  std::cout << "\tparser::interpret : " << this->list.front() << std::endl;
  if (boost::regex_match(this->list.front().c_str(), what, msz))
    std::cout << "\t" << what[1] << std::endl;
  return (true);
}
