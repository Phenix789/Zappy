/*
** parser_str_check_contain.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 11:01:01 2012 vincent kersuzan
** Last update Tue May 29 11:06:16 2012 vincent kersuzan
*/

#include	"parser.h"

bool	parser_str_check_contain(char *str, char *authorized)
{
  int	authorized_index;
  int	str_index;
  bool	matched;

  str_index = 0;
  while (str[str_index])
    {
      matched = false;
      authorized_index = 0;
      while (authorized[authorized_index])
	{
	  if (authorized[authorized_index] == str[str_index])
	    matched = true;
	  authorized_index++;
	}
      if (matched == false)
	return (false);
      str_index++;
    }
  return (true);
}
