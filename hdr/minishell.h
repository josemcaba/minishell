/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:04:39 by jocaball          #+#    #+#             */
/*   Updated: 2024/01/14 02:27:14 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "../libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <readline/readline.h>

void	prompt(void);

# define DEF_COLOR	"\033[0;39m"
# define BLACK		"\033[0;30m"
# define GRAY	  	"\033[0;90m"
# define RED		"\033[1;91m"
# define GREEN		"\033[1;92m"
# define YELLOW		"\033[0;93m"
# define BLUE		"\033[0;94m"
# define MAGENTA	"\033[0;95m"
# define CYAN		"\033[0;96m"
# define WHITE		"\033[0;97m"

#endif

// space tab  newline  |  &  ;  (  )  <  >
 