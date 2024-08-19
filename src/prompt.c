/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:57:17 by jocaball          #+#    #+#             */
/*   Updated: 2024/08/19 02:36:44 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Esta función imprime el prompt y lee la línea de comandos.
// Si la línea de comandos no está vacía, la añade al historial.
// Devuelve la línea de comandos leída o NULL si no se ha podido leer.

#include "../hdr/minishell.h"

char	*ft_strjoinfree(char *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

char	*prompt(void)
{
	char	*cmdline;
	char	*t_cmdline;
	char	*prompt;
	int		i;

	prompt = ft_strjoin(YELLOW, getenv("USER"));
	prompt = ft_strjoinfree(prompt, "@msh42");
	prompt = ft_strjoinfree(prompt, DEF_COLOR);
	prompt = ft_strjoinfree(prompt, ":");
	prompt = ft_strjoinfree(prompt, CYAN);
	i = ft_memcmp(getenv("PWD"), getenv("HOME"), ft_strlen(getenv("HOME")));
	if (i == 0)
	{
		prompt = ft_strjoinfree(prompt, "~");
		prompt = ft_strjoinfree(prompt, \
					getenv("PWD") + ft_strlen(getenv("HOME")));
	}
	else
		prompt = ft_strjoinfree(prompt, getenv("PWD"));
	prompt = ft_strjoinfree(prompt, DEF_COLOR);
	prompt = ft_strjoinfree(prompt, "$ ");
	cmdline = readline(prompt);
	free(prompt);
	if (cmdline == NULL)
		return (NULL);
	t_cmdline = ft_strtrim(cmdline, " \t");
	if (ft_strlen(t_cmdline) > 0)
		add_history(t_cmdline);
	return (t_cmdline);
}
