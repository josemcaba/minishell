/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 12:52:40 by jocaball          #+#    #+#             */
/*   Updated: 2023/08/25 12:18:26 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_putchar_fd('\n', 2);
	exit(EXIT_FAILURE);
}
