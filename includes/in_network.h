/*
** in_network.h for zappy in /home/duval_q//Documents/projects/zappy/includes
** 
** Made by quentin duval
** Login   <duval_q@epitech.net>
** 
** Started on  Tue May 29 08:01:10 2012 quentin duval
** Last update Tue May 29 08:22:05 2012 quentin duval
*/

#ifndef		IN_NETWORK_H_
# define	IN_NETWORK_H_

# include	"network.h"

SOCKET          extract_from_listener(void *data);
SOCKET          extract_from_socket(void *data);
void		execute_from_socket(void *data);
void            execute_from_listener(void *data);


#endif	/*	IN_NETWORK_H_	*/
