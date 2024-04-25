/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yachadla <yachadla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 21:00:10 by yachadla          #+#    #+#             */
/*   Updated: 2024/04/23 21:09:45 by yachadla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>


char *get_next_line(int fd)
{
	char 			*buffer;
	static char		*reserve;
	char			*line;
	int				byte_read;
	
	line = NULL;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	if (byte_read == -1)
		return (NULL);
	buffer[byte_read] = '\0';
	byte_read = read(fd, buffer, BUFFER_SIZE);
	if (ft_strchr(buffer, '\n' )!= 0)
	{
		line = ft_decoupe(buffer, reserve, BUFFER_SIZE, ft_strchr(buffer, '\n'));
		free(buffer);
		return (line);
	}
	while (ft_strchr(buffer, '\n') == 0 && byte_read > 0)
	{
		byte_read = read(fd, buffer, BUFFER_SIZE);
		if (byte_read == -1)
		return (NULL);
		buffer[byte_read] = '\0';
		reserve = ft_strjoin(reserve, buffer);
	}
	if (ft_strchr(buffer, '\n' )!= 0)
	{
		line = ft_decoupe(buffer, reserve, BUFFER_SIZE, ft_strchr(buffer, '\n'));
		free(buffer);
		line = ft_strjoin(reserve, line);
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

	fd = open("exemple.txt", O_RDONLY);
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
