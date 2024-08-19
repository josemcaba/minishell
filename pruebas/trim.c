#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s && (*s != (char)c))
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while ((i < (dstsize - 1)) && src[i] && dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize > 0)
		dst[i] = '\0';
	return (ft_strlen(src));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*strtrimmed;

	start = 0;
	if (ft_strlen(s1) == 0)
		end = 0;
	else
		end = ft_strlen(s1) - 1;
	while ((start < end) && ft_strchr(set, s1[start]))
		start++;
	while ((end > start) && ft_strchr(set, s1[end]))
		end--;
	strtrimmed = (char *)malloc((end - start + 1) * sizeof(char));
	if (!strtrimmed)
		return (NULL);
	ft_strlcpy(strtrimmed, s1 + start, end - start + 1);
	return (strtrimmed);
}

int	main(void)
{
	char	*s1 = "    ";
	char	*set = " \t";
	char	*trimmed;

	trimmed = ft_strtrim(s1, set);
	printf("Original string: \"%s\"\n", s1);
	printf("Trimmed string: \"%s\"\n", trimmed);
	free(trimmed);
	return (0);
}
