/**
 *
 *
 *
 */

#ifndef __GAME_H__
#define	__GAME_H__

#include "game_info.h"
#include "logger.h"
#include "client.h"
#include "kernel.h"

/*player*/
t_player *player_create(t_team *team, int x, int y);
void player_free(t_player *player);

/*team*/
t_team *team_create(char *name, int slots);
void team_free(t_team *team);
bool team_add_player(t_team *team, t_player *player);
void team_remove_player(t_team *team, t_player *player);

/*world*/
void world_add_player(t_player *player, int x, int y);
void world_remove_player(t_player *player);
bool world_move_player(t_player *player);
bool world_move_to(t_player *player, t_orientation direction);
t_tile *world_get_tile(int x, int y);

/*game*/
bool game_init(int x, int y, int nb_slots);
int game_width();
int game_height();

bool game_start();
void game_play_free_player();

void game_create_team(char *team);
void game_add_team(t_team *team);
t_team *game_get_team(char *name);

void game_add_free_player(t_player *player);
void game_remove_free_player(t_player *player);
t_player *game_get_slot(char *team);

void game_action_choose(t_player *player);
void game_action_move(t_player *player);
void game_action_left(t_player *player);
void game_action_right(t_player *player);

void game_world_dump();

/*callback*/
void		player_connect_nbr_cb(t_client *client, char *command);
void		player_death_cb(t_client *client, char *command);
void		player_drop_end_cb(t_client *client, int error);
void		player_drop_start_cb(t_client *client, char *command);
void		player_expulse_end_cb(t_client *client, int error);
void		player_expulse_start_cb(t_client *client, char *command);
void		player_fork_end_cb(t_client *client, int error);
void		player_fork_start_cb(t_client *client, char *command);
void		player_forward_end_cb(t_client *client, int error);
void		player_forward_start_cb(t_client *client, char *command);
void		player_incantation_end_cb(t_client *client, int error);
void		player_incantation_start_cb(t_client *client, char *command);
void		player_inventory_end_cb(t_client *client, int error);
void		player_inventory_start_cb(t_client *client, char *command);
void		player_left_end_cb(t_client *client, int error);
void		player_left_start_cb(t_client *client, char *command);
void		player_look_end_cb(t_client *client, int error);
void		player_look_start_cb(t_client *client, char *command);
void		player_right_end_cb(t_client *client, int error);
void		player_right_start_cb(t_client *client, char *command);
void		player_take_end_cb(t_client *client, int error);
void		player_take_start_cb(t_client *client, char *command);

#endif
