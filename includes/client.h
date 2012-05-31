/*
** client.h for zappy in /home/duval_q//Documents/projects/zappy/includes
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Wed May 30 21:54:04 2012 quentin duval
** Last update Wed May 30 22:19:24 2012 damien vezant
*/

#ifndef __CLIENT_H__
#define	__CLIENT_H__

typedef struct s_client t_client;

#include <stdbool.h>
#include "list.h"
#include	"game.h"
#include	"network.h"
#include "parser.h"
#include "logger.h"

#define CLIENT_MAX_ACTIONS 10

typedef struct s_client_manager
{
	t_list clients;
} t_client_manager;

struct s_client
{
	t_socket *socket;
	t_player *player;
	t_list actions;
	bool busy;
};

/*client manager*/
void client_manager_init();
void client_manager_destroy();
int client_manager_count();
void _client_manager_add(t_client *client);
void _client_manager_remove(t_client *client);

t_client *client_manager_retrieve_from_socket(t_socket *socket);
t_client *client_manager_retrieve_from_player(t_player *player);

/*client*/
t_client *client_create(t_socket *socket);
t_client *client_init(t_client *client, t_socket *socket);
void client_destroy(t_client *client);

t_socket *client_get_socket(t_client *client);
t_player *client_get_player(t_client *client);
bool client_set_player(t_client *client, t_player *player);

int client_count_action(t_client *client);
t_command *client_next_action(t_client *client);
bool client_save_action(t_client *client, t_command *command);

#endif
