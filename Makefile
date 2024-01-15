NAME = Philosophers

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LFLAGS =

SRC = main.c \
	  ./src/basic/basic_funcs.c \
	  ./src/philos/philo_init.c \
	  ./src/philos/philo_sleep.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
