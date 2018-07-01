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

NAME =	lib1_sdl.so
SDL2 = SDL2.framework
NAMEGOAL =	../
NAMEGOAL_NAME = $(NAMEGOAL)$(NAME)
cur-dir   := $(shell pwd)
#[----------------------------------HEADERS-----------------------------------]#

HEADERS_PATH =	../includes/

INC =-I$(HEADERS_PATH)

#[---------------------------------LIBRARIES----------------------------------]#

LIBSDL_PATH = ./SDL2.framework/Versions/A/
LIBSDL = SDL2

LIBS = $(LIBSDL_PATH)$(LIBSDL)

#[--------------------------------COMPILATION---------------------------------]#

CCXX = clang++
FLAGS	= -Wall -Wextra -Werror -std=c++11
LIB_FLAG = -shared -fPIC


#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH 	= ./

ROOT = sdlWindow.cpp

FUNCTIONS =

SRC = $(ROOT) $(FUNCTIONS)
OBJ=$(SRC:%.cpp=%.o)
#OBJ = $(SRC:.cpp=.o)

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


all: $(SDL2) $(NAME)

$(NAME): $(OBJ)
	@ $(CCXX) $(FLAGS) $(LIB_FLAG) -o $(NAME) $(OBJ) $(INC) $(LIBS);
	@ rm -f $(OBJ);
	@ mv $(NAME) $(NAMEGOAL) ;

%.o: %.cpp
	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC)   -g ;

$(SDL2):
	@ curl -o sdl2.dmg https://www.libsdl.org/release/SDL2-2.0.8.dmg; \
	hdiutil attach sdl2.dmg; \
	rm -rf SDL2.framework;
	@ cd ;  cp -R ../../../Volumes/SDL2/SDL2.framework $(cur-dir) ; hdiutil eject ../../../Volumes/SDL2;
	@ rm sdl2.dmg

clean:
	@ rm -f $(OBJ)
	@ rm -rf SDL2.framework
	@ echo "$(YELLOW)[cleanSDL2]$(RESET)"

fclean: clean
	@ rm -f $(NAMEGOAL)$(NAME)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
