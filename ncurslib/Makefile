# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrassokh <mrassokh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/12 09:31:31 by mrassokh          #+#    #+#              #
#    Updated: 2017/06/03 14:38:10 by mrassokh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	ncurslib.so

NAMEGOAL =	../

cur-dir   := $(shell pwd)
#[----------------------------------HEADERS-----------------------------------]#

HEADERS_PATH =	../includes/

INC =-I$(HEADERS_PATH)

#[---------------------------------LIBRARIES----------------------------------]#

LIBNCURS = -lncurses

#[--------------------------------COMPILATION---------------------------------]#

CCXX = clang++
FLAGS	= -Wall -Wextra -Werror -std=c++11
LIB_FLAG = -shared -fPIC $(LIBNCURS)

#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH 	= ./

ROOT = ncursWindow.cpp

FUNCTIONS =


SRC = $(ROOT) $(FUNCTIONS)

OBJ = $(SRC:.cpp=.o)


#[-----------------------------------COLORS-----------------------------------]\
#

GREEN                   =       \033[32m
RESET                   =       \033[39m
YELLOW                  =       \033[33m
RED                     =       \033[31m


#[------------------------------------MAKE------------------------------------]\
#

vpath %.cpp $(SRC_PATH)
vpath %.hpp $(HEADERS_PATH)

all: $(NAME)

$(NAME):  extract $(OBJ)
	@echo "\033[0;32mCompile ncurslib ...\033[0m"
	@ $(CCXX) $(FLAGS) $(LIB_FLAG) -o $(NAME) $(OBJ) $(INC) $(LIBS)
	rm -f $(OBJ)
	mv $(NAME) $(NAMEGOAL)
	@ echo "$(GREEN)[$(NAME)]$(RESET)"

%.o:  %.cpp
	@echo "\033[0;32mCreating object file\033[0m \033[31m$@\033[0m"
	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC)   -g
	@ printf ' $(GREEN)[add]$(RESET) $<\n'

extract:

clean:
	@ rm -f $(OBJ)
	@ echo "$(YELLOW)[clean]$(RESET)"

fclean: clean
	@ rm -f $(NAME)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
