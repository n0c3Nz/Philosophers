## COLORS ##
END = \033[0m
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
BLUE = \033[1;34m
WHITE = \033[1;37m


NAME = Philosophers
CC = gcc -I./inc
CFLAGS = -Wall -Wextra -Werror #-fsanitize=thread

OS = $(shell uname)
ifeq ($(OS),Darwin)
	LFLAGS = -L./inc -lpthread 
endif

OBJ_DIR = .obj
SRC_DIR = ./src

SRC = $(shell find $(SRC_DIR) -type f -name '*.c')
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) -c -o $@  $<
$(NAME): $(OBJ)
	@echo "$(NAME): $(BLUE)Objects compiled succesdfully$(END)"
	@echo "$(NAME): $(BLUE)Linking...$(END)"
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LFLAGS)
	@echo "$(NAME): $(BLUE)$(NAME) created !$(END)"


clean:
	@echo "$(NAME): $(BLUE)Deleting files$(END)"
	@rm -rf $(OBJ)
	@rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean all re
