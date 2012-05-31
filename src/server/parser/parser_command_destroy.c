/*
** parser_command_destroy.c for zappy in /home/kersuz_v//Zappy/src/server/parser
** 
** Made by vincent kersuzan
** Login   <kersuz_v@epitech.net>
** 
** Started on  Tue May 29 07:55:20 2012 vincent kersuzan
** Last update Wed May 30 23:00:33 2012 vincent kersuzan
*/

#include	<stdlib.h>

#include	"parser.h"

static void     parser_command_list_elem_destroy(void *del)
{
  t_argument	*elem;

  if (!del)
    return ;
  elem = (t_argument *)del;
  free(elem->data);
  free(elem);
}

void    parser_command_destroy(t_command *command)
{
  if (!command)
    return ;
  printf("command_destroy\n");
  free(command->instruction);
  free(command->original_str);
  list_foreach(&(command->arguments), &parser_command_list_elem_destroy);
  list_clear(&(command->arguments));
  free(command);
}
