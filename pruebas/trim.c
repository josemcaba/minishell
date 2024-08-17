#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static size_t	ft_strlen(const char *s)
{
    size_t	len;

    len = 0;
    while (s[len] != '\0')
        len++;
    return (len);
}

static char	*ft_strchr(const char *s, int c)
{
    while (*s != (char)c)
    {
        if (*s == '\0')
            return (NULL);
        s++;
    }
    return ((char *)s);
}

static size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
    size_t	i;

    i = 0;
    if (dstsize != 0)
    {
        while (src[i] != '\0' && i < dstsize - 1)
        {
            dst[i] = src[i];
            i++;
        }
        dst[i] = '\0';
    }
    return (ft_strlen(src));
}

char    *ft_strtrim(char const *s1, char const *set)
{
    char	*trimmed;
    size_t	len;
    size_t	i;
    size_t	j;

    if (s1 == NULL || set == NULL)
        return (NULL);
    i = 0;
    while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
        i++;
    j = ft_strlen(s1);
    while (j > i && ft_strchr(set, s1[j - 1]) != NULL)
        j--;
    len = j - i;
    trimmed = malloc(len + 1);
    if (trimmed == NULL)
        return (NULL);
    ft_strlcpy(trimmed, s1 + i, len + 1);
    return (trimmed);
}

int main()
{
    char *s1 = "A";
    char *set = " Hl";
    char *trimmed = ft_strtrim(s1, set);

    printf("Original string: \"%s\"\n", s1);
    printf("Trimmed string: \"%s\"\n", trimmed);

    free(trimmed);
    return 0;
}