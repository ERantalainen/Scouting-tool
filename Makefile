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
OBJS = $(SRCS:.cpp=.o)
HEADERS = Team.hpp
NAME = ScoutApp
CC = @c++
FLAGS = -Wall -Wextra -Werror -std=c++20 -fsanitize=address -g

all: $(NAME)

%.o: %.cpp $(HEADERS)
	$(CC) $(FLAGS) -c $< -o $@
	@echo -e $(LGREEN)Compiling OBJ files$(OFF)

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(OBJS) -o $(NAME)
		@echo -e $(GREEN)Compiled $(NAME)$(OFF)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all