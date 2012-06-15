##
## Makefile for  in /home/frizac_b/Svn
##
## Made by Alexandre Frizac
## Login   <frizac_b@epitech.net>
##
## Started on  Mon Feb  6 14:18:30 2012 Alexandre Frizac
## Last update Fri Jun 15 17:04:51 2012 Alexandre Frizac
##

NAME		= a.out

INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src

DEBUG_FLAGS	+= -ggdb3
#DEBUG_FLAGS	+= -DDEBUG
#DEBUG_FLAGS	+= -DDEBUG_NETWORK
DEBUG_FLAGS	+= -DDEBUG_GRAPH
#DEBUG_FLAGS	+= -DSHOW_FPS

CC		= g++
CXXFLAGS	+= -I include
CXXFLAGS	+= -Wall -Wextra -Wshadow
LDFLAGS		+= -l sfml-system -l sfml-graphics -l sfml-window -l sfml-network
LDFLAGS		+= -l boost_regex

SRC	= $(addprefix src/, \
		exception.cpp \
		Game/data.cpp \
		Game/map.cpp \
		Game/player.cpp \
		Game/tiles.cpp \
		gui.cpp \
		main.cpp \
		Network/network.cpp \
		Network/sfml_network.cpp \
		Parser/cmd.cpp \
		Parser/parser.cpp \
		Position/position.cpp \
		Sfml/draw.cpp \
		Sfml/end.cpp \
		Sfml/event.cpp \
		Sfml/Image.cpp \
		Sfml/init.cpp \
		Sfml/intro.cpp \
		Sfml/sfml.cpp \
		Sfml/wait.cpp \
		)
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:$(SRC_DIR)/%.cpp=%.o))

all: $(NAME)

m:
	make fclean
	make all -j 5

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
