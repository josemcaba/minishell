/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 10:57:17 by jocaball          #+#    #+#             */
/*   Updated: 2024/01/07 18:40:18 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Esta función imprime el prompt y lee la línea de comandos.
// Si la línea de comandos no está vacía, la añade al historial.
// Devuelve la línea de comandos leída o NULL si no se ha podido leer.

#include "../hdr/minishell.h"

char	*prompt(void)
{
	int		i;
	char	*cmdline;
	char	*t_cmdline;

	printf("%s%s%s%s", YELLOW, getenv("USER"), "@", "msh42");
	printf("%s%s%s", DEF_COLOR, ":", GREEN);
	i = ft_memcmp(getenv("PWD"), getenv("HOME"), ft_strlen(getenv("HOME")));
	if (i == 0)
		printf("%s%s", "~", getenv("PWD") + ft_strlen(getenv("HOME")));
	else
		printf("%s", getenv("PWD"));
	printf("%s", DEF_COLOR);
	cmdline = readline("$ ");
	if (cmdline == NULL)
		return (NULL);
	t_cmdline = ft_strtrim(cmdline, " ");	
	printf("%s\n", t_cmdline);
	if (ft_strlen(t_cmdline) > 0)
		add_history(t_cmdline);
	free(cmdline);	
	return (t_cmdline);
}
