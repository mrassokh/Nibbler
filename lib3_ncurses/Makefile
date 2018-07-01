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

CXX =			clang++

NAME =			lib3_ncurses.so
NAMEGOAL =    	../
NAMEGOAL_NAME = $(NAMEGOAL)$(NAME)

CFLAGS =		-Wall -Werror -Wextra -std=c++11

LIB_FLAG =		-shared -fPIC

NCURSE_FLAGS =	-lncurses

HEADERS_PATH =  ../includes/

INC =			-I$(HEADERS_PATH)

SRC =			ncursesWindow.cpp

OBJ =			$(SRC:%.cpp=%.o)



%.cpp.o: %.cpp
	@$(CXX) $(CFLAGS) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	@$(CXX) $(CFLAGS) $(NCURSE_FLAGS) $(LIB_FLAG) -o $(NAME) $(OBJ) $(INC)
	@ mv $(NAME) $(NAMEGOAL) ;

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re