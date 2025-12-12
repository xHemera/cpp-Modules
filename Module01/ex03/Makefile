CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98
SRC			= src/main.cpp src/HumanA.cpp src/HumanB.cpp src/Weapon.cpp
OBJ			= $(SRC:.cpp=.o)
NAME		= main

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
