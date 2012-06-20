
#ifndef __GUI_H__
#define	__GUI_H__

#include "list.h"
#include "logger.h"
#include "client.h"
#include "game.h"

#define GUI_BUFFER_SIZE 64

typedef t_client t_gui;

typedef struct s_gui_manager
{
	t_list guis;
} t_gui_manager;

bool gui_init();
void gui_destroy();

void gui_connect(t_gui *gui);
void gui_execute(t_gui *gui, char *command);
int gui_send(t_gui *gui, char *msg);
void gui_send_all(char *msg);

void gui_action_forward(t_player *player);
void gui_action_left(t_player *player);
void gui_action_right(t_player *player);
void gui_action_take(t_player *player, t_item item);
void gui_action_drop(t_player *player, t_item item);

void gui_command_msz(t_gui *gui, char *command);
void gui_command_mct(t_gui *gui, char *command);
void gui_command_bct(t_gui *gui, char *command);
void gui_command_tna(t_gui *gui, char *command);
void gui_command_ppo(t_gui *gui, char *command);
void gui_command_plv(t_gui *gui, char *command);
void gui_command_pin(t_gui *gui, char *command);
void gui_command_sgt(t_gui *gui, char *command);
void gui_command_sst(t_gui *gui, char *command);

#endif
