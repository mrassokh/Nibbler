# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmalkevy <rmalkevy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/30 17:31:31 by rmalkevy          #+#    #+#              #
#    Updated: 2017/06/30 18:38:10 by rmalkevy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib3_glfw.so
GLFW3 = glfw-3.2.1
NAMEGOAL =    ../
NAMEGOAL_NAME = $(NAMEGOAL)$(NAME)
cur-dir   := $(shell pwd)
#[----------------------------------HEADERS-----------------------------------]#

HEADERS_PATH = ../includes/
GLFWINCLUDES = $(DIRGLFW)/include

INC = -I$(HEADERS_PATH) -I$(GLFWINCLUDES)

#[---------------------------------LIBRARIES----------------------------------]#

FRAMEWORKS =  -L$(GLFW3)/src -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework GLUT

#[--------------------------------COMPILATION---------------------------------]#

CCXX = clang++
FLAGS    = -Wall -Wextra -Werror -std=c++11 -Wno-deprecated-declarations
LIB_FLAG = -shared -fPIC


#[----------------------------------SOURCES-----------------------------------]#

SRC_PATH     = ./

ROOT = glfwWindow.cpp

SRC = $(ROOT)
OBJ=$(SRC:%.cpp=%.o)

#[-----------------------------------COLORS-----------------------------------]#

GREEN                   =       \033[32m
RESET                   =       \033[39m
YELLOW                  =       \033[33m
RED                     =       \033[31m


#[------------------------------------MAKE------------------------------------]#

vpath %.cpp $(SRC_PATH)
vpath %.hpp $(HEADERS_PATH)


all: $(GLFW3) $(NAME)

$(NAME): $(OBJ)
	@ $(CCXX) $(FLAGS) $(LIB_FLAG) -o $(NAME) $(OBJ) $(INC) $(FRAMEWORKS);
	@ rm -f $(OBJ);
	@ mv $(NAME) $(NAMEGOAL) ;

%.o: %.cpp
	@ $(CCXX) $(FLAGS) -c $< -o $@  $(INC) $(FRMPATH) -g ;

$(GLFW3):
	@echo "Loading \033[32mGLFW\033[0m"
	@curl -L -O -# --progress-bar https://github.com/glfw/glfw/releases/download/3.2.1/glfw-3.2.1.zip
	@unzip -q glfw-3.2.1.zip
	@rm glfw-3.2.1.zip
	@cd $(GLFW3) && cmake . && make
	@echo "GLFW \033[33m Ready \033[0m"

clean:
	@ rm -f $(OBJ)
	@ rm -rf $(GLFW3)
	@ echo "$(YELLOW)[cleanGLFW3]$(RESET)"

fclean: clean
	@ rm -f $(NAMEGOAL)$(NAME)
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
