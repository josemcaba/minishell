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

#include "../hdr/minishell.h"

void	prompt(void)
{
	int		i;

	printf("%s", YELLOW);
	printf("%s%s%s", getenv("USER"), "@", "msh42");
	printf("%s%s", DEF_COLOR, ":");
	printf("%s", GREEN);
	i = ft_memcmp(getenv("PWD"), getenv("HOME"), ft_strlen(getenv("HOME")));
	if (i == 0)
		printf("%s%s", "~", getenv("PWD") + ft_strlen(getenv("HOME")));
	else
		printf("%s", getenv("PWD"));
	printf("%s", DEF_COLOR);
}
