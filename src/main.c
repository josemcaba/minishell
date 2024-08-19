/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:30:38 by jocaball          #+#    #+#             */
/*   Updated: 2024/08/19 00:50:03 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../hdr/minishell.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmdline;

	(void)envp;
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (1);
	}
	while (42)
	{
		cmdline = prompt();
		if (cmdline == NULL)
			continue ;
		if (fork() == 0)
		{
			execve(cmdline, argv, envp);
		}
		else
		{
			wait(NULL);
			free(cmdline);
		}
	}
	return(0);
}
