/**
 *
 *
 *
 */

#ifndef __GAME_H__
#define	__GAME_H__

void game_turn();

void game_player_add(t_player *player);
void game_player_remove(t_player *player);

void game_autoplay_add_player(t_player *player);
void game_autoplay_get_player(t_player *player);

void protocol_cb_*(t_client *client, t_command *command);

#endif
