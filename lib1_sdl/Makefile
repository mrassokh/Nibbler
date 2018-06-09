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

NAMEGOAL =	../

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
	@echo "\033[0;32mCompile sdllib ...\033[0m"
	@ $(CCXX) $(FLAGS) $(LIB_FLAG) -o $(NAME) $(OBJ) $(INC) $(LIBS)
	rm -f $(OBJ)
	mv $(NAME) $(NAMEGOAL)
	@ echo "$(GREEN)[$(NAME)]$(RESET)"

%.o:  %.cpp
	@echo "\033[0;32mCreating object file\033[0m \033[31m$@\033[0m"
#	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC) -I ../sdllib/SDL2-2.0.8/include/SDL.h  -g
	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC)   -g
	@ printf ' $(GREEN)[add]$(RESET) $<\n'

extract:
	curl -o sdl2.dmg https://www.libsdl.org/release/SDL2-2.0.8.dmg
	#open . sdl2.dmg
	#cp SDL2.framework ./


	#curl -o sdl2.tar.gz https://www.libsdl.org/release/SDL2-2.0.8.tar.gz
	#tar jxf sdl2.tar.gz
	#mkdir build1 ; cd build1 ; cmake ../SDL2-2.0.8/ ;
	#mkdir build ; cd build ; CC=../SDL2-2.0.8/build-scripts/gcc-fat.sh  CXX=../SDL2-2.0.8/build-scripts/g++-fat.sh ../SDL2-2.0.8/configure ; make
	#cd SDL2-2.0.8; mkdir build ; cd build ; ../configure --prefix=$HOME/config/non-packaged; make install
	#rm sdl2.tar.gz


	#7z x sdl2.dmg
	hdiutil attach sdl2.dmg;
	rm -rf SDL2.framework;
	@ cd ;  cp -R ../../../Volumes/SDL2/SDL2.framework $(cur-dir) ; hdiutil eject ../../../Volumes/SDL2;
	#hdiutil eject ../../../Volumes/SDL2;
	#cp ../../../Volumes/SDL2/SDL2.framework/Headers/* $(cur-dir)/sdl_Headers; cp ../../../Volumes/SDL2/SDL2.framework/SDL2 $(cur-dir); hdiutil eject ../../../Volumes/SDL2;
	#;cp -R ../../../Volumes/SDL2/SDL2.framework $(cur-dir))

	rm sdl2.dmg;


clean:
	@ rm -f $(OBJ)
	@ rm -rf SDL2.framework
	@ echo "$(YELLOW)[clean]$(RESET)"

fclean: clean
	@ rm -f $(NAMEGOAL)$(NAME)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
