/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 23:09:07 by jocaball          #+#    #+#             */
/*   Updated: 2024/08/18 23:16:11 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_NUM_PARAMS 64

void	parse_command(char *cmd, char **params)
{
	char	*param;
	int		param_index;
	int		cmd_index;
	int		in_quotes;
	int		backslash;

	param_index = 0;
	cmd_index = 0;
	in_quotes = 0;
	backslash = 0;
	for(int i = 0; i < MAX_CMD_LEN; i++) {
		if (cmd[i] == '\\')
		{
			backslash = 1;
			continue ;
		}
		if (backslash)
			backslash = 0;
		else if (cmd[i] == '\"')
			in_quotes = !in_quotes;
		else if ((cmd[i] == '|' && !in_quotes) || cmd[i] == '\0')
		{
			param = malloc(i - cmd_index + 1);
			strncpy(param, &cmd[cmd_index], i - cmd_index);
			param[i - cmd_index] = '\0';
			params[param_index++] = param;
			if (cmd[i] == '\0')
				break ;
			cmd_index = i + 1;
		}
	}
	params[param_index] = NULL;
}
