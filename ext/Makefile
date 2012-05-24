##
## Makefile for extlibc in /home/epitech/c/extlibc
##
## Made by claude ramseyer
## Login   <ramsey_c@epitech.net>
##
## Started on  Mon Feb 27 10:00:00 2011 claude ramseyer
## Last update mon Feb 27 10:00:01 2011 claude ramseyer
##

DYNAMIC_LIB = libextlibc_dynamic.so
STATIC_LIB = libextlibc_static.a
HEADERS = list.h map.h errors.h

CC = gcc
RM = rm -rf
CP = cp

INCLUDE_DIR = includes
SRC_DIR	= src
OBJ_DIR	= obj
LIB_DIR	= .
INSTALL_DIR = ../lib
HEADER_DIR = ../includes

NAZI = -W -Wall -Werror -Wextra

CFLAGS += -I$(INCLUDE_DIR)
CFLAGS += -fPIC
CFLAGS += $(NAZI)

LDFLAGS = -shared

LIST_DIR = containers/list
LIST_SRC = \
	list.c \
	list_private.c \
	list_add.c \
	list_get.c \
	list_pop.c \
	list_utils.c \
	list_algorithm.c \
	list_iter_base.c \
	list_iter_modif.c

MAP_DIR = containers/map
MAP_SRC = \
	map.c \
	map_operation.c \
	map_utils.c \
	map_algorithm.c

ERRORS_DIR = errors
ERRORS_SRC = \
	errors.c

ASRC += $(addprefix $(LIST_DIR)/, $(LIST_SRC))
ASRC += $(addprefix $(MAP_DIR)/, $(MAP_SRC))
ASRC += $(addprefix $(ERRORS_DIR)/, $(ERRORS_SRC))

SRC = $(addprefix $(SRC_DIR)/, $(ASRC))
OBJ = $(addprefix $(OBJ_DIR)/, $(ASRC:.c=.o))

all: $(DYNAMIC_LIB) $(STATIC_LIB) install fclean

$(DYNAMIC_LIB):	$(OBJ)
	$(CC) -o $(DYNAMIC_LIB) $(OBJ) $(LDFLAGS)

$(STATIC_LIB):	$(OBJ)
	ar rc $(STATIC_LIB) $(OBJ)
	ranlib $(STATIC_LIB)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(LIB_DIR)/$(DYNAMIC_LIB)
	$(RM) $(LIB_DIR)/$(STATIC_LIB)
	$(RM) $(OBJ_DIR)

install:
	$(CP) $(LIB_DIR)/$(DYNAMIC_LIB) $(INSTALL_DIR)/$(DYNAMIC_LIB)
	$(CP) $(LIB_DIR)/$(STATIC_LIB) $(INSTALL_DIR)/$(STATIC_LIB)
	$(CP) $(addprefix $(INCLUDE_DIR)/, $(HEADERS)) $(HEADER_DIR)/

uninstall:
	$(RM) $(INSTALL_DIR)/$(DYNAMIC_LIB)
	$(RM) $(INSTALL_DIR)/$(STATIC_LIB)
	$(RM) $(addprefix $(HEADER_DIR)/, $(HEADERS))

re: fclean all
