#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str || !s)
	{
		if (str)
			ft_free(str);
		if (s)
			ft_free(s);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!str)
		return (ft_free(s1));
	i = -1;
	j = 0;
	if (!s1)
	{
		ft_free(str);
		return (ft_strdup(s2));
	}
	while (s1[++i])
		str[i] = s1[i];
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	ft_free(s1);
	return (str);
}
char	*ft_strchr(const char *s, int c)
{
	int					i;
	unsigned char		ca;
	char				*str;

	ca = (unsigned char)c;
	str = (char *)s;
	i = 0;
	if (!s)
		return (NULL);
	while (str[i])
	{
		if (str[i] == ca)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == ca)
		return ((char *)&str[i]);
	return (NULL);
}
