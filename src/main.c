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
	char	*args[] = {"/bin/pwd", NULL};

	(void)envp;
	if (argc != 1)
	{
		printf("Usage: %s\n", argv[0]);
		return (1);
	}
	while (42)
	{
		prompt();
		cmdline = readline("$ ");
		// Esto es para que el padre ejecute el comando
		printf("Soy el padre\n");
		if (fork() == 0)
		{
			// Esto es para que el hijo ejecute el comando
			sleep(10);
			execve(cmdline, args, envp);
		}
		// Esto es para que el padre espere a que el hijo termine
		wait(NULL);
		printf("Sigo siendo el padre\n");
		free(cmdline);
	}
	return (0);
}
