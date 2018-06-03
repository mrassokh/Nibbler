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

NAME =	nibbler
SDLLIB = sdllib.so
NCURSLIB = ncurslib.so
#[----------------------------------HEADERS-----------------------------------]#

HEADERS_PATH =	./includes/

INC =-I$(HEADERS_PATH)

#[---------------------------------LIBRARIES----------------------------------]#
LIB_SDL_PATH = sdllib/
LIBS_NCURS_PATH = ncurslib/
LIBS_GLUT_PATH =


LIBPATH = ./static_libs/

LIBFT = -lft

LIBS = $(LIBFT)
LIBFTPATH = $(LIBPATH)libft
LIBFTINC = $(LIBFTPATH)/includes
LIBSINC = -I$(LIBFTINC)
LIBSDIR = -L$(LIBPATH)
LIBRIRIES = $(LIBS) $(LIBSINC) $(LIBSDIR)
#[--------------------------------COMPILATION---------------------------------]#

CC = gcc
CCXX = clang++
FLAGS	= -Wall -Wextra -Werror -std=c++11
RUNFLAGS = "-Wl,-rpath," $(LIB_SDL_PATH)
LIB_SO_FLAG = -shared -fPIC



#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH 	= ./src/

ROOT = main.cpp

FUNCTIONS = nibbler.cpp SquareSegment.cpp GameField.cpp SnakeSegment.cpp \
			SnakeHead.cpp Snake.cpp FoodSegment.cpp CustomExeptions.cpp \
			FoodProcessor.cpp Render.cpp SnakeProcessor.cpp Obstacle.cpp \
			ObstacleBuilder.cpp DotObstacleBuilder.cpp ObstacleDirector.cpp


SRC = $(ROOT) $(FUNCTIONS)
OBJ_DIR = ./obj/
OBJ = $(addprefix $(OBJ_DIR),$(SRC:.cpp=.o))


#[-----------------------------------COLORS-----------------------------------]\
#

GREEN                   =       \033[32m
RESET                   =       \033[39m
YELLOW                  =       \033[33m
RED                     =       \033[31m


#[------------------------------------MAKE------------------------------------]\
#
.PHONY: make_libs
.PHONY: make_libsdl_so

vpath %.cpp $(SRC_PATH)
vpath %.hpp $(HEADERS_PATH)

all: $(NAME)

$(NAME): $(OBJ) make_libs
	@echo "\033[0;32mCompile program ...\033[0m"
	@ $(CCXX) $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(RUNFLAGS) -g
	@ echo "$(GREEN)[$(NAME)]$(RESET)"

$(OBJ_DIR)%.o: %.cpp
	@echo "\033[0;32mCreating object file\033[0m \033[31m$@\033[0m"
	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC) -g
	@ printf ' $(GREEN)[add]$(RESET) $<\n'

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

clean:
	@ rm -f $(OBJ)
	@ rm -rf $(OBJ_DIR)
	@ echo "$(YELLOW)[clean]$(RESET)"

fclean: clean
	@ rm -f $(NAME) $(SDLLIB) $(NCURSLIB)
	@ cd ./$(LIB_SDL_PATH); make clean;
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all

make_libs: make_libsdl_so make_libncurs_so

make_libsdl_so:
	@ cd ./$(LIB_SDL_PATH);\
	make ;
	@ echo "$(GREEN)[libsdl_so compile]$(RESET)"

make_libncurs_so:
	@ cd ./$(LIBS_NCURS_PATH);\
	make ;
	@ echo "$(GREEN)[libncurs_so compile]$(RESET)"

make_libglut_so:
	@ cd ./$(LIBS_GLUT_PATH);\
	make ;
	@ echo "$(GREEN)[libglut_so compile]$(RESET)"
