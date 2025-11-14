# Reset
OFF='\033[0m'

# Regular Colors
BLACK='\033[0;30m'
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[0;33m'
BLUE='\033[0;34m'
LGREEN='\033[0;35m'
CYAN='\033[0;36m'
WHITE='\033[0;37m'

SRCS = main.cpp Team.cpp
SRC_DIR = ./
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJ_DIR = ./obj
HEADERS = Team.hpp
NAME = ScoutApp
CC = @c++
FLAGS = -Wall -Wextra -Werror -std=c++20 -g

all: $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(dir $@)
	@c++ $(CFLAGS) $(STD) -c $< -o $@
	echo -e $(LGREEN)Compilingobj files

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo -e $(GREEN)Compiled $(NAME)$(OFF)

clean:
	@rm -f $(OBJ_DIR)
	echo -e $(RED)Cleaning OBJ files$(OFF)

fclean: clean
	@rm -f $(NAME)
	echo -e $(RED)Cleaning executable$(OFF)

re: fclean all

.PHONY: clean fclean re all