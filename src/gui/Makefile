##
## Makefile for  in /home/frizac_b/Svn
##
## Made by Alexandre Frizac
## Login   <frizac_b@epitech.net>
##
## Started on  Mon Feb  6 14:18:30 2012 Alexandre Frizac
## Last update Mon Jun 11 16:50:19 2012 Alexandre Frizac
##

NAME		= a.out

INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src

DEBUG_FLAGS	+= -ggdb3
DEBUG_FLAGS	+= -DDEBUG

CC		= g++
CXXFLAGS	+= -I include
CXXFLAGS	+= -Wall -Wextra -Wshadow -O2
LDFLAGS		+= -l sfml-system -l sfml-graphics -l sfml-window -l sfml-network
LDFLAGS		+= -l boost_regex

SRC	= $(addprefix src/, \
		class/game/data.cpp \
		class/game/map.cpp \
		class/game/player.cpp \
		class/game/tiles.cpp \
		class/gui/gui.cpp \
		class/network/network.cpp\
		class/network/sfml_network.cpp\
		class/parser.cpp \
		class/position/position.cpp \
		class/sfml/draw.cpp \
		class/sfml/event.cpp \
		class/sfml/LoadImage.cpp \
		class/sfml/screen.cpp \
		class/sfml/sfml.cpp \
		class/sfml/wait.cpp \
		debug_gui.cpp\
		gui.cpp\
		main.cpp\
		network_iteration.cpp \
		parser_cmd.cpp\
		utils.cpp\
		)
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:$(SRC_DIR)/%.cpp=%.o))

all: $(NAME)

m:
	make fclean
	make all -j 4

$(NAME): $(OBJ)
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

.PHONY: all clean fclean re m
