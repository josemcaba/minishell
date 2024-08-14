/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:30:38 by jocaball          #+#    #+#             */
/*   Updated: 2024/08/14 02:35:46 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmdline;

	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (1);
	}
	while (*envp) 
	{
		if (ft_strncmp(*envp, "PATH=", 5) == 0)
			printf("%s\n", *envp);
		envp++;
	}
	while (42)
	{
		prompt();
		cmdline = readline("");
		if (!fork())
			execve(cmdline, argv, NULL);
		wait(NULL);
		free(cmdline);
	}
	return (0);
}
