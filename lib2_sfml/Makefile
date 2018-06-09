CLANG = clang++

NAME = lib2_sfml.so

NAMEGOAL = ../

NAME_DIRECTORY = SFML-2.5.0-macOS-clang

DIR_SFML = ./$(NAME_DIRECTORY)/

GL =	-framework opengl \
		$(DIR_SFML)/lib/libsfml-graphics.2.5.0.dylib \
		$(DIR_SFML)/lib/libsfml-window.2.5.0.dylib \
		$(DIR_SFML)/lib/libsfml-system.2.5.0.dylib \
		-L $(DIR_SFML)/lib -Wl,-rpath,$(DIR_SFML)/lib \


CFLAGS = -Wall -Werror -Wextra -std=c++11

LIB_FLAG = -shared -fPIC

SFML_FLAGS = -I $(DIR_SFML)/include

HEADER = ../includes/sfmlWindow.hpp

SRC = sfmlWindow.cpp

OBJ = $(SRC:.cpp=.cpp.o)

%.cpp.o: %.cpp
	@$(CLANG) $(CFLAGS) $(SFML_FLAGS) -c $< -o $@

all: $(NAME)

$(NAME): extract $(OBJ) $(HEADER)
	@echo "\033[0;32mCompile sfmllib ...\033[0m"
	@ $(CLANG) $(CFLAGS) $(LIB_FLAG) $(SFML_FLAGS) -o $(NAME) $(OBJ) $(GL)
	rm -f $(OBJ)
	mv $(NAME) $(NAMEGOAL)

extract:
	curl -OL https://www.sfml-dev.org/files/SFML-2.5.0-macOS-clang.tar.gz
	tar -zxvf SFML-2.5.0-macOS-clang.tar.gz
	rm SFML-2.5.0-macOS-clang.tar.gz


clean:
	@ rm -rf $(OBJ)
	@ rm -rf $(NAME_DIRECTORY)
	@ echo "$(RED)[clean]$(RESET)"

fclean: clean
	@ echo "$(RED)[fclean]$(RESET)"

re: fclean all
