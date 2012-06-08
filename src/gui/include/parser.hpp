#ifndef __PARSER_HPP_
#define __PARSER_HPP_

#include <boost/regex.hpp>
#include <map>
#include <list>
#include <string>
#include "game.hpp"

namespace color
{
  extern const char *red;
  extern const char *orange;
  extern const char *white;
};

namespace pfunc
{
  void	fpmsz(game::data &data, const std::string &cmd);
};

typedef void (*funcpar)(game::data &data, const std::string &cmd);

class parser
{
public:
  parser();
  ~parser();

public:
  void	parse(std::string &buffer);
  bool	interpret(game::data &data);

protected:
  void	fpmsz(game::data &data, const std::string &cmd);

private:
  std::list<std::string>		list;
  std::map<std::string, funcpar>	func;
};

#endif /* __PARSER_HPP_ */
