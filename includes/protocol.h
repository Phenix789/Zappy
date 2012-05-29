
#ifndef __PROTOCOL_H__
#define	__PROTOCOL_H__

#define COEF_TIME 126
#define NAME_TEAM_SIZE 60

#define RC_FOOD 0
#define RC_LINEMATE 1
#define RC_DERAUMERE 2
#define RC_SIBUR 3
#define RC_MENDIANE 4
#define RC_PHIRAS 5
#define RC_THYSTAME 6

#define TIME_MOVE 7
#define TIME_LEFT 7
#define TIME_RIGHT 7
#define TIME_VIEW 7
#define TIME_INVENTAIRE 7
#define TIME_TAKE 7
#define TIME_DROP 7
#define TIME_EJECT 7
#define TIME_MSG 7
#define TIME_SPELL 300
#define TIME_FORK 42
#define TIME_INFO 0

typedef bool (*pt_newsession_cb)(t_session *session);

typedef struct s_protocol
{
	t_socket listen;
	t_list commands;
	pt_newsession_cb new_session;
} t_protocol;

typedef struct s_session
{
	t_socket socket;
} t_session;

typedef void t_command;
typedef void (*pt_command_cb)(t_session *client, t_command *command);

bool protocol_init(pt_newsession_cb new_session);
bool protocol_close();

bool protocol_register_command(int command, char *mask, pt_command_cb callback);
int protocol_send_command(t_session *client, int command, ...);


t_session *session_create(t_socket *);
t_session *session_init(t_socket *);
void session_close(t_session *session);
#define session_destroy free

#endif
