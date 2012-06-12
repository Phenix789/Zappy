/*
** client.h for zappy in /home/duval_q//Documents/projects/zappy/includes
**
** Made by quentin duval
** Login   <duval_q@epitech.net>
**
** Started on  Wed May 30 21:54:04 2012 quentin duval
** Last update Tue Jun 12 16:23:58 2012 quentin duval
*/

#ifndef __CLIENT_H__
#define	__CLIENT_H__

typedef struct s_command_callback t_command_callback;
typedef struct s_client_manager t_client_manager;
typedef struct s_client t_client;

#include <stdbool.h>
#include "list.h"
#include "game.h"
#include "network.h"
#include "logger.h"

#define CLIENT_MAX_ACTIONS 10

typedef void	(*t_execute_cb) (t_client *, char *);

#define CLM_CB_SIZE 32

struct s_command_callback
{
	char instruction[CLM_CB_SIZE + 1];
	char mask[CLM_CB_SIZE + 1];
	unsigned int length;
	t_execute_cb callback;
};

struct s_client_manager
{
  t_list	clients;
  t_list	commands;
  t_socket	listen;
};

struct s_client
{
	t_socket *socket;
	t_player *player;
	t_list actions;
	bool busy;
};
#define CLP_ID(client) ((client)->player ? (client)->player->id : -1)

/*client manager*/
bool client_manager_init(int port);
void client_manager_destroy();
int client_manager_count();
void _client_manager_add(t_client *client);
void _client_manager_remove(t_client *client);

void clm_command_register(char *instruction, char *mask, t_execute_cb callback);
t_command_callback *clm_command_retrieve(char *action);

t_client *clm_retrieve_from_socket(t_socket *socket);
t_client *clm_retrieve_from_player(t_player *player);

/*client*/
t_client *client_create(t_socket *socket);
t_client *client_init(t_client *client, t_socket *socket);
void client_destroy(t_client *client);

t_socket *client_get_socket(t_client *client);
t_player *client_get_player(t_client *client);
bool client_set_player(t_client *client, t_player *player);

void client_connect(t_socket *new_sock);
void client_unconnect(t_client *client);

int client_action_count(t_client *client);
bool client_action_save(t_client *client, char *action);
void client_action_finish(t_client *client);
void client_execute(t_client *client, char *action);

bool client_player_search(t_client *client, char *team);
void client_receive(t_socket *socket, t_client *client);
int client_send(t_client *client, char *mask, ...);

void client_consume_food(t_client *client);
void client_food_dead(t_client *client);

#endif
