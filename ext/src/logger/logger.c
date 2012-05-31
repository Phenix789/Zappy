/*
** logger.c for extlibc in /home/epitech/c/extlibc
**
** Made by claude ramseyer
** Login   <ramsey_c@epitech.net>
**
** Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
** Last update Mon Feb 27 10:00:01 2011 claude ramseyer
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "logger.h"

t_logger *g_logger = NULL;

int logger_init(int level, char *name, int verbose)
{
  logger_destroy();
  if ((g_logger = malloc(sizeof(t_logger))) == NULL)
    return EXIT_FAILURE;
  memset(g_logger, 0, sizeof(t_logger));
  g_logger->level = level;
  g_logger->verbose = verbose;
  if (!name)
    name = LOGGER_FILENAME;
  strncpy(g_logger->name, name, LOGGER_FILENAME_SIZE);
  g_logger->file = fopen(g_logger->name, "a+");
  if (g_logger->file == NULL)
    return EXIT_FAILURE;
  g_logger->init = 1;
  atexit(&logger_destroy);
  return EXIT_SUCCESS;
}

void logger_destroy()
{
  if (g_logger)
    {
      if (g_logger->init)
	fclose(g_logger->file);
      free(g_logger);
      g_logger = NULL;
    }
}

int logger_is_init()
{
  return g_logger && g_logger->init;
}

void logger_set_level(int level)
{
  if (logger_is_init())
    g_logger->level = level;
}
