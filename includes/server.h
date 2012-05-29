/**
 *
 *
 *
 */

#ifndef __SERVER_H__
#define	__SERVER_H__

#include "list.h"
#include "protocol.h"

typedef int t_socket;

typedef struct s_coord {
	int x;
	int y;
} t_coord;

typedef struct s_server {
	t_socket listener;
	int width;
	int height;
	int delay;
	int round;
	t_list teams;
	t_list clients;
} t_server;

typedef struct s_team {
	char name[NAME_TEAM_SIZE + 1];
	t_list players;
} t_team;

typedef struct s_player {
	int x;
	int y;
	int level;
	int life;
	t_list inventaire;
	t_client * client;
} t_player;

typedef struct s_client {
	t_socket socket;
	t_player * player;
} t_client;
typedef t_client t_gui;

typedef struct s_case {
	int x;
	int y;
	t_list ressources;
	t_player * player;
} t_case;

#endif
