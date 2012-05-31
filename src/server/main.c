/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 02:23:43 2012 quentin duval
** Last update Thu May 31 01:23:51 2012 vincent kersuzan
*/

#include	<stdio.h>

#include	"parser.h"
#include	"session.h"

void	unit_test(char *data, char *mask)
{
  t_command	*command;

  if (!data || !mask)
    printf("un pointeur d entree au moins est a nul\n");
  else
    printf("checking : data = \"%s\"\nwith : mask = \"%s\"\n",
	 data, mask);
  if ((command = parser_parse(data, mask)))
    {
      int	i = 0;

      while (i < list_size(&command->arguments))
	{
	  printf("string %d {value = \"%s\"}\n",
		 i, parser_get_string(command, i));
	  printf("int %d {value = \"%d\"}\n",
		 i, parser_get_int(command, i));
	  i++;
	}
      parser_command_destroy(command);
    }
  else
    printf("dismatch\n");
}

int     main(void)
{
  unsigned int	i;

  session_create();
  i = 0;
  while (i < 10)
    {
      session_register_in("instruction", "mask", NULL);
      session_register_out(0, "mask");
      i++;
    }
  session_destroy();

  unit_test("instruction str1 52", "%s %s %d");
  unit_test("pilou split siooooo", "%ssplit%s");
  unit_test("pilou 512", "%s %d");
  unit_test(NULL, "%s%d");
  unit_test("sdpflspdflpsf", NULL);
  unit_test("plop sdf sdfsdf", "pilou");
  unit_test("instruction pilou 13", "%s %s %d");
  //  unit_test("plop pilou", "%s %");
  return (0);
}
