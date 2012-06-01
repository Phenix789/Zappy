##
## Makefile for  in /home/frizac_b/Svn
##
## Made by Alexandre Frizac
## Login   <frizac_b@epitech.net>
##
## Started on  Mon Feb  6 14:18:30 2012 Alexandre Frizac
## Last update Fri Jun  1 15:10:39 2012 Alexandre Frizac
##

NAME		= a.out

INC_DIR		= include
OBJ_DIR		= obj
SRC_DIR		= src

CC		= g++
CXXFLAGS	+= -I include
CXXFLAGS	+= -Wall -Wextra -Wshadow -g
LDFLAGS		+= -l sfml-system -l sfml-window
LDFLAGS		+= -l boost_regex

SRC	= $(addprefix src/, \
		class/dynlib.cpp \
		class/game.cpp \
		class/network.cpp\
		class/parser.cpp \
		class/sfml.cpp \
		gui.cpp\
		main.cpp\
		network.cpp\
		parser_cmd.cpp\
		)
OBJ	= $(addprefix $(OBJ_DIR)/, $(SRC:$(SRC_DIR)/%.cpp=%.o))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p obj
	@mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CXXFLAGS)

clean:
	rm -f $(OBJ) $(SYSCALL)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
