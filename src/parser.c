/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 17:58:53 by jocaball          #+#    #+#             */
/*   Updated: 2024/01/07 18:01:18 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CMD_LEN 1024
#define MAX_NUM_PARAMS 64

void	parse_command(char* cmd, char** params) {
	int paramIndex = 0;
	int cmdIndex = 0;
	int inQuotes = 0;
	int backslash = 0;

	for(int i = 0; i < MAX_CMD_LEN; i++) {
		if(cmd[i] == '\\') {
			backslash = 1;
			continue;
		}
		if(backslash) {
			backslash = 0;
		} else if(cmd[i] == '\"') {
			inQuotes = !inQuotes;
		} else if((cmd[i] == '|' && !inQuotes) || cmd[i] == '\0') {
			char* param = malloc(i - cmdIndex + 1);
			strncpy(param, &cmd[cmdIndex], i - cmdIndex);
			param[i - cmdIndex] = '\0';
			params[paramIndex++] = param;
			if(cmd[i] == '\0') {
				break;
			}
			cmdIndex = i + 1;
		}
	}
	params[paramIndex] = NULL;
}
