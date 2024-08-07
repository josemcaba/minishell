# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/06 10:19:51 by jocaball          #+#    #+#              #
#    Updated: 2024/01/07 14:54:43 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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

# Recopila todos los archivos header ".h" del directorio "hdr".
HEADERS = $(wildcard $(HDR_DIR)/*.h)

# Genera la lista de objetos correspondiente a los archivos fuente.
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Regla por defecto.	
$(NAME): all

all: $(LIBFT) $(PROGRAM)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

# Regla para generar archivos objeto desde archivos fuente.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

# Regla para generar el programa ejecutable.
$(PROGRAM): $(OBJECTS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_DIR) -lft -lreadline
	@norminette $(SRC_DIR) $(HDR_DIR) $(LIBFT_DIR) | grep -v OK! || true

clean:
	@rm -rf $(OBJ_DIR)/*
	@$(MAKE) -s -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(PROGRAM)
	@$(MAKE) -s -C $(LIBFT_DIR) fclean

re: fclean all

val:
	$(CC) -g $(CFLAGS) -o $(PROGRAM) $(OBJECTS) -L$(LIBFT_DIR) -lft -lreadline
	@valgrind -s --leak-check=full --show-leak-kinds=all ./$(PROGRAM)

# Reglas que no son archivos.
.PHONY: $(NAME) all clean fclean re val
