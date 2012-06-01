#ifndef __PARSER_HPP_
#define __PARSER_HPP_

#include <list>
#include <string>
#include "game.hpp"

class parser
{
public:
  parser();
  ~parser();

public:
  bool	parse(std::string &buffer);
  bool	interpret(game::data &data);

private:
  std::list<std::string>	list;
};

#endif /* __PARSER_HPP_ */
