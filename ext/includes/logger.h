/*
** logger.h for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#ifndef __LOGGER_H__
#define	__LOGGER_H__

#include <stdio.h>

#define LOGGER_FILENAME "log.log"
#define LOGGER_FILENAME_SIZE 60

#define LG_MESSAGE 0x1
#define LG_WARNING 0x2
#define LG_ERROR 0x4
#define LG_DEBUG 0x8

#define LG_LOG (LG_MESSAGE | LG_WARNING | LG_ERROR)
#define LG_ALLLOG (LG_LOG | LG_DEBUG)
#define LG_NOLOG 0

#define LG_VERBOSE 1

#define LG_GET_MSGLVL(lvl) (lvl & LG_MESSAGE ? "message" : (lvl  & LG_WARNING ? "warning" : (lvl & LG_ERROR ? "error" : "debug")))
#define LG_GET_COLOR(lvl) (lvl & LG_MESSAGE ? "32" : (lvl  & LG_WARNING ? "33" : (lvl & LG_ERROR ? "1;31" : "36")))

typedef struct s_logger
{
	FILE *file;
	int level;
	int init;
	int verbose;
	char name[LOGGER_FILENAME_SIZE + 1];
} t_logger;

int logger_init(int level, char *name, int verbose);
void logger_destroy();
int logger_is_init();
void logger_set_level(int level);

int logger_message(char *message, ...);
int logger_warning(char *message, ...);
int logger_error(char *message, ...);
int logger_debug(char *message, ...);

int logger_verbose(char *message, ...);

#endif
