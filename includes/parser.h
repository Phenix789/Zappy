/*
** parser.h for zappy in /home/kersuz_v//Zappy/includes
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 02:26:28 2012 vincent kersuzan
** Last update Tue May 29 03:46:54 2012 vincent kersuzan
*/

#ifndef		PARSER_H_
# define	PARSER_H_

typedef struct	s_command
{
  char		*str;
}		t_command;

t_command	*parser_parse(char *data, char *mask);

#endif	/*	PARSER_H_	*/
