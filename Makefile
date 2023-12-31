PROGRAM = minishell

SRC_DIR = src
HDR_DIR = hdr
OBJ_DIR = obj
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./$(HDR_DIR)

# Recopila todos los archivos fuente ".c" del directorio "src".
SOURCES = $(wildcard $(SRC_DIR)/*.c)

# Genera la lista de objetos correspondiente a los archivos fuente.
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

$(NAME): all

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
	@rm -rf $(OBJ_DIR)/*
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: $(NAME) all clean fclean re
