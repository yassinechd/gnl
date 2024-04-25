/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:00:14 by yachadla          #+#    #+#             */
/*   Updated: 2024/04/23 22:12:54 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}
int ft_strchr(const char *s, int c)
{
	unsigned int		i;
	unsigned char		ca;
	char				*str;

	ca = (unsigned char)c;
	str = (char *)s;
	i = 0;
	if (!s)
		return (0);
	while (str[i])
	{
		if (str[i] == ca)
			return (i + 1);
		i++;
	}
	if (str[i] == ca)
		return (i + 1);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	sizetot;
	size_t	i;
	size_t	j;

	sizetot = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (sizetot + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}
char	*ft_strdup(const char *s)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = 0;
	if (!s)
		return (NULL);
	while (s[len])
		len++;
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
char *ft_decoupe(char *buffer, char **rest, int taille, int pos_n)
{
	int i;
	int	j;
	char *reserve;

	i = 0;
	reserve = malloc (sizeof(char) * (pos_n));
	if (!reserve)
		return (NULL);
	while (i < pos_n)
	{
		reserve[i] = buffer[i];
		i++;
	}
	reserve[i] = '\0';
	j = 0;
	if (pos_n < taille)
	{
		*rest = malloc (sizeof(char) * ((taille - pos_n) + 1));
		if (!*rest)
			return (NULL);
		while ((pos_n + j) < taille)
		{
			(*rest)[j] = buffer[pos_n + j];
			j++;
		}
	}
	(*rest)[j] = '\0';
	return (reserve);
}
