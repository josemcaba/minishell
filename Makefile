CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./include
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = libft
PROGRAM = minishell
LIBFT = $(LIBFT_DIR)/libft.a

# Recopila todos los archivos fuente ".c" del directorio "src".
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Genera la lista de objetos correspondiente a los archivos fuente.
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

$NAME: all

all: $(LIBFT) $(PROGRAM)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Regla para generar archivos objeto desde archivos fuente.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Regla para generar el programa ejecutable.
$(PROGRAM): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft

clean:
	rm -rf $(OBJ_DIR)/*
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $NAME all clean fclean re
