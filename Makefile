NAME = Philosophers

CC = gcc -I./include
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread
LFLAGS = -lpthread

SRC = main.c \
	  ./src/basic/basic_funcs.c \
	  ./src/philos/philo_init.c \
	  ./src/philos/philo_sleep.c \
	  ./src/philos/philo_eat.c \
	  ./src/philos/philo_think.c \
	  ./src/philos/philo_dead.c \
	  ./src/philos/philo_routine.c

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
