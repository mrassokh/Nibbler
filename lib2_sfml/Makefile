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

SFMLDIR=SFML2.2

#include_dir=/usr/X11R6/include $(SFMLDIR)/SFML-2.2-osx-clang-universal/include
include_dir=$(SFMLDIR)/SFML-2.2-osx-clang-universal/include
#library_dir=/usr/X11R6/lib
cairo=cairo
x11=X11
sfml=SFML sfml-graphics sfml-window sfml-system OpenGL
src_dir=
obj_dir=

SFMLFRAMDIR=$(SFMLDIR)/SFML-2.2-osx-clang-universal/Frameworks
PWD=$(shell pwd)
CXX=clang++
FRAMSFML=-F $(SFMLFRAMDIR) $(addprefix -framework , $(sfml))
LIBRARY= $(LIBCAIRO) $(LIBX11)
INCLUDE=$(addprefix -I, $(include_dir))
#LIB=$(addprefix -L, $(library_dir)) $(LIBRARY)
LIB=# $(LIBRARY)

NAME=lib2_sfml.so
NAMEGOAL = ../
CPPFLAGS = -g3 -Wall -Wextra -Werror -std=c++11  $(INCLUDE)
#VPATH=$(include_dir) $(library_dir) $(src_dir)
VPATH=$(include_dir) $(src_dir)
vpath %.dylib #$(library_dir)

SRC=sfmlWindow.cpp

OBJ=$(SRC:%.cpp=%.o)

.SECONDARY: $(OBJ)

.PHONY: all clean fclean re

all: $(SFMLDIR) $(NAME)

$(SFMLDIR):
	curl -OL http://www.sfml-dev.org/files/SFML-2.2-osx-clang-universal.tar.gz
	mkdir $(SFMLDIR)
	tar zxvfC SFML-2.2-osx-clang-universal.tar.gz $(SFMLDIR)
	rm SFML-2.2-osx-clang-universal.tar.gz
	cd $(SFMLFRAMDIR) && ln -s ../extlibs/freetype.framework

$(NAME): $(OBJ)
	@ $(CXX) $(CPPFLAGS) -o $@ $(OBJ) $(LIB) $(FRAMSFML) -rpath $(PWD)/$(SFMLFRAMDIR) -dynamiclib
	@ rm -f $(OBJ)
	@ mv $(NAME) $(NAMEGOAL)

extract:
	git clone https://github.com/SFML/SFML.git


clean:
	@ rm -rf $(OBJ)
	@ rm -rf $(SFMLDIR)
	@ echo "$(YELLOW)[cleanSFML]$(RESET)"


fclean: clean
	rm -rf $(NAME)  ./**/#*# ./**/.DS_Store ./**/.#*

re: fclean all
