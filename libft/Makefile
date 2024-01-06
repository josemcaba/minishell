# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/18 14:19:51 by jocaball          #+#    #+#              #
#    Updated: 2024/01/06 14:22:16 by jocaball         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HDR = libft.h
SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
LIB = ar rcs 

all : $(NAME)

$(NAME): $(OBJ) $(HDR)
	@$(LIB) $(NAME) $(OBJ)
	@echo "$(GREEN)\n-------> Library $(YELLOW)$(NAME)$(GREEN) has been created\n$(DEF_COLOR)"

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : $(NAME) all clean fclean re

DEF_COLOR = \033[0;39m
BLACK	  =	\033[0;30m
RED		  =	\033[1;91m
GREEN	  =	\033[1;92m
YELLOW	  = \033[0;93m
BLUE	  = \033[0;94m
MAGENTA	  = \033[0;95m
CYAN	  = \033[0;96m
GRAY	  = \033[0;90m
WHITE	  = \033[0;97m
