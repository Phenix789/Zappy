##
## Makefile for project_boot in /home/duval_q//Documents/project_reference
## 
## Made by quentin duval
## Login   <duval_q@epitech.net>
## 
## Started on  Tue Dec 20 09:40:56 2011 quentin duval
## Last update Thu May 31 02:59:25 2012 vincent kersuzan
##

#########################
######## user part ######
#########################

##binary name
NAME =		zappy_server zappy_client zappy_gui

SUBMAKEPATH= ext

##sources files
##
## note : variable must be formed like xxx_OBJ
## where xxx is the binary name
##
zappy_server_OBJ=	server/main.o \
			server/parser/parser.o \
                        server/parser/parser_get_int.o \
                        server/parser/parser_get_string.o \
                        server/parser/parser_is_match.o \
                        server/parser/parser_command_destroy.o \
                        server/parser/parser_count_arguments.o \
                        server/parser/parser_str_check_contain.o \
                        server/parser/parser_find_key.o \
                        server/parser/parser_type_map.o \
                        server/parser/parser_get_from_map.o \
                        server/parser/parser_extract_elem.o \
                        server/parser/parser_command_create.o \
                        server/parser/parser_argument_setter.o \
                        server/parser/parser_save_data.o \
			server/session/session_send.o \
			server/session/session_register_in.o \
			server/session/session_register_out.o \
			server/session/session_treat_data.o \
			server/session/session_create.o \
			server/session/session_create.o \
			server/session/session_destroy.o \
			server/session/session_get_session.o \
			server/network/network.o \
			server/network/network_listen.o \
			server/network/network_listen_to.o \
			server/network/network_manage_socket.o \
			server/network/network_socket.o \
			server/network/network_socket_connect.o \
			server/network/network_socket_rw.o \
			server/network/network_private_access.o \
			server/clock/clock.o \
			server/clock/clock_speed.o \
			server/clock/clock_tick.o \
			server/clock/clock_turn.o

zappy_gui_OBJ=		gui/main.o

zappy_client_OBJ=	client/main.o

##needed libraries
##
## note: variabl must be formed like xxx_LIBS
## where xxx is the binary name
##
zappy_server_LIBS=	-lextlibc_static

zappy_client_LIBS=

zappy_gui_LIBS=

##binary location:
BIN_DIR =	.

##libraries
LDFLAGS =

##control vars
DEBUG="yes"

##langage specs (tested for :ccp and c)                                             
EXT=c
########end user part

########used binaries
CC=            gcc
RM =            rm -rf
########used binaries end

#############################
######## generic part #######
#############################

########project folders
LIB_DIR =       lib
INCLUDE_DIR =   includes
SRC_DIR =       src
OBJ_DIR =       obj
DEP_DIR =       .deps
DOC_DIR =	doc
########end project folders 

########compilation flags
CXXFLAGS +=     -Werror -Wall -Wextra
CXXFLAGS +=	-I$(INCLUDE_DIR)

ifeq ($(DEBUG),"yes")
CXXFLAGS += -g
endif

LDFLAGS +=	-L $(LIB_DIR)
########compilation flags end

########build all project
all:		$(SUBMAKEPATH)	$(NAME)


$(SUBMAKEPATH):
	@make -C $@

########multi-cible template
define PROGRAM_template =
$(1)_OBJS= $(addprefix $(OBJ_DIR)/, $($(1)_OBJ))
$(1)_DEPS= $(addprefix $(DEP_DIR)/, $($(1)_OBJ:.o=.d))
$(1): $$($(1)_OBJS)
ALL_OBJS   += $$($(1)_OBJS)
DEP	   += $$($(1)_DEPS)
endef

########multicible generation
$(foreach prog,$(NAME),$(eval $(call PROGRAM_template,$(prog))))

########generate binary
$(NAME):
	@echo generate $@ in folder :  $(BIN_DIR)
	@mkdir -p $(BIN_DIR)
	@$(CC) $^ -o $(BIN_DIR)/$@ $(LDFLAGS) $($@_LIBS)

########look at dependancies
-include $(DEP)

########generate object files and dependancies
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.$(EXT)
	@echo making $@
	@mkdir -p $(@D)
	@echo compiling $< in $@
	@$(CC) -o $@ -c $< $(CXXFLAGS)

$(DEP_DIR)/%.d: $(SRC_DIR)/%.$(EXT)
	@echo generate dependencies at : $(DEP_DIR)/$*.d
	@mkdir -p $(DEP_DIR)/$(*D)
	@$(CC) -MM $< $(CXXFLAGS) -o $@
	@echo -n $(OBJ_DIR)/$(*D)/ > $@.tmp;
	@cat $@ >> $@.tmp
	@sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.tmp > $@;
	@cat $@ > $@.tmp
	@sed -e 's/.*://' -e 's/\\$$//' < $@.tmp | fmt -1 | \
	sed -e 's/^ *//' -e 's/$$/:/' >> $@
	@rm -f $(DEP_DIR)/$*.d.tmp


########clean objects
clean:		
	@echo cleaning objects
	@$(RM) $(ALL_OBJS)
	@make clean -C $(SUBMAKEPATH)

########clean all build files
fclean:		clean
	@echo cleaning all
	@$(RM) $(DEP)
	@$(RM) $(NAME)
	@make fclean -C $(SUBMAKEPATH)

flush:	fclean
	@echo clear folders
	@$(RM) $(OBJ_DIR)/* $(DEP_DIR)/*

########use this YOU lazy programmer!
init:
	@echo initialise project folders
	@mkdir -p $(LIB_DIR)
	@echo library folder is $(LIB_DIR)
	@mkdir -p $(SRC_DIR)
	@echo source folder is $(SRC_DIR)
	@mkdir -p $(INCLUDE_DIR)
	@echo include folder is $(INCLUDE_DIR)
	@mkdir -p $(OBJ_DIR)
	@echo dependancies folder is $(DEP_DIR)
	@mkdir -p $(DEP_DIR)
	@echo objects folder is $(OBJ_DIR)
	@mkdir -p $(DOC_DIR)
	@echo documentation folder is $(DOC_DIR)
	@echo *--------init ended----------*

########beware this command destroys ALL the project
erase:
	@$(RM) $(DEP_DIR) $(LIB_DIR) $(SRC_DIR)\
	 $(INCLUDE_DIR) $(OBJ_DIR) $(BIN_DIR)/$(NAME) $(DOC_DIR)

########yay! do it again!
re:
	@make -s fclean
	@make -s all

########who is stupid?
.PHONY:		all clean fclean re init erase $(SUBMAKEPATH)
