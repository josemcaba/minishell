/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaball <jocaball@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 12:43:09 by jocaball          #+#    #+#             */
/*   Updated: 2024/08/23 03:24:50 by jocaball         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Parametros  : s1  : La string que debe ser recortada.
//               set : Los caracteres a eliminar de la string.
// Devuelve    : La string recortada.
//               NULL si falla la reserva de memoria.
// Descripcion : Elimina todos los caracteres de la string 'set' desde el
//               principio y desde el final de 's1', hasta encontrar un
//               caracter no perteneciente a 'set'. La string resultante se
//               devuelve con una reserva de malloc(3).

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrimmed;
	
	if (ft_strlen(s1) == 0)
	{
		strtrimmed = (char *)malloc(1 * sizeof(char));
		if (!strtrimmed)
			return (NULL);
		strtrimmed[0] = '\0';
		return (strtrimmed);
	}
	start = 0;
	end = ft_strlen(s1) - 1;
	while ((start < end) && ft_strchr(set, s1[start]))
		start++;
	while ((end > start) && ft_strchr(set, s1[end]))
		end--;
	strtrimmed = (char *)malloc((end - start + 2) * sizeof(char));
	if (!strtrimmed)
		return (NULL);
	ft_strlcpy(strtrimmed, s1 + start, end - start + 2);
	return (strtrimmed);
}
