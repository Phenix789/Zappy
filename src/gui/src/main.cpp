/*
** main.c for zappy in /home/duval_q//Documents/projects/zappy/src
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Tue May 29 02:23:59 2012 quentin duval
// Last update Wed May 30 20:51:32 2012 Alexandre Frizac
*/

#include "gui.hpp"

int     main(int __attribute__((unused))ac, char __attribute__((unused))**av)
{
  data_thread	data;

  game::launch_gui(data);
  return (EXIT_SUCCESS);
}
