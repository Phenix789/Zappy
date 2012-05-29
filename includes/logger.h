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
#define LG_NOLOG 0

typedef struct s_logger
{
	FILE *file;
	int level;
	int init;
	char name[LOGGER_FILENAME_SIZE + 1];
} t_logger;

int logger_init(int level, char *name);
void logger_destroy();
int logger_is_init();
void logger_set_level(int level);

int logger_message(char *message, ...);
int logger_warning(char *message, ...);
int logger_error(char *message, ...);
int logger_debug(char *message, ...);

#endif