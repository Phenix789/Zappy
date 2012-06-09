##
## Makefile for  in /home/frizac_b/Svn
##
## Made by Alexandre Frizac
## Login   <frizac_b@epitech.net>
##
## Started on  Mon Feb  6 14:18:30 2012 Alexandre Frizac
## Last update Sat Jun  9 14:16:49 2012 Alexandre Frizac
##

NAME		= a.out

INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src

DEBUG_FLAGS	= -g -DDEBUG

CC		= g++
CXXFLAGS	+= -I include
CXXFLAGS	+= -Wall -Wextra -Wshadow -O2
LDFLAGS		+= -l sfml-system -l sfml-graphics -l sfml-window
LDFLAGS		+= -l boost_regex -l boost_thread

SRC	= $(addprefix src/, \
		class/dynlib.cpp \
		class/game/data.cpp \
		class/game/map.cpp \
		class/game/player.cpp \
		class/game/tiles.cpp \
		class/network.cpp\
		class/parser.cpp \
		class/sfml.cpp \
		gui.cpp\
		main.cpp\
		network.cpp\
		parser_cmd.cpp\
		debug.cpp\
		)
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:$(SRC_DIR)/%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	echo $(LDFLAGS)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(DEBUG_FLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p obj
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS) $(DEBUG_FLAGS)

clean:
	rm -f $(OBJ) $(SYSCALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
