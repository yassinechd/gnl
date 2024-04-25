/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:00:10 by yachadla          #+#    #+#             */
/*   Updated: 2024/04/23 22:26:22 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

void ft_free(char *str)
{
	free(str);
	str = NULL;
}

char *get_next_line(int fd)
{
	char 			*buffer;
	static char		*reserve;
	char			*line;
	int				byte_read;

	buffer = malloc (sizeof(char) * (BUFFER_SIZE + 1));
	byte_read = 1;
	while (ft_strchr(buffer, '\n') == 0 && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (reserve == NULL)
			reserve = ft_strdup(buffer);
		reserve = ft_strjoin(reserve, buffer);
	}
	if (ft_strchr(buffer, '\n') > 0)
	{
		line = ft_strdup(reserve);
		ft_free(reserve);
		line = ft_strjoin(line, ft_decoupe(buffer, &reserve, BUFFER_SIZE, ft_strchr(buffer, '\n')));
		ft_free(buffer);
		return (line);
	}
	line = ft_strdup(reserve);
	free(buffer);
	free(reserve);
	return (line);
}

int main(void)
{
	int fd;
	char *str;
	//char *rest;
	//char *res;

	//res = ft_decoupe(buff, &rest, ft_strlen(buff), ft_strchr(buff, 'o'));
	//printf("%d\n", ft_strchr(buff, 'o'));
	//printf("%zu\n", ft_strlen(buff));
	//printf("%s\n", res);
	//printf("%s\n", rest);
	//fd = open("exemple.txt", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		printf("%s\n", str);
		str = NULL;
	}
	close(fd);
	return (0);
}
