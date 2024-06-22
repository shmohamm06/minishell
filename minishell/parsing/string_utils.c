#include "lexer.h"



char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;
	size_t			strln;

	strln = ft_strlen(s);
	if (!s)
		return (0);
	if (start > strln)
		return (ft_strdup(""));
	if (len > strln - start)
		return (ft_strdup(s + start));
	i = 0;
	substr = (char *)malloc((len * sizeof(char)) + 1);
	if (!substr)
		return (0);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		return (i);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = ft_strlen(s1);
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len;
	char	*s1_2;
	int		i;

	if ((!s1 || !s2) || (!s1 && !s2))
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	s1_2 = (char *)malloc(len * sizeof(char) + 1);
	i = 0;
	if (!s1_2)
		return (0);
	while (*s1)
	{
		s1_2[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		s1_2[i] = *s2;
		s2++;
		i++;
	}
	s1_2[i] = '\0';
	return (s1_2);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && s2[i] != '\0')
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	while (i < n && s1[i] != '\0')
	{
		if ((((unsigned char *)s1)[i] != ((unsigned char *)s2)[i]))
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}