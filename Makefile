CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
PROGRAM = your_executable_name
LIBFT = $(LIBFT_DIR)/libft.a

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

$NAME: all

all: $(LIBFT) $(PROGRAM)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -rf $(OBJ_DIR)/*
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $NAME all clean fclean re
