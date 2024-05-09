#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
void *ft_free(char *str)
{
	if (str)
		free(str);
	str = NULL;
	return (NULL);
}

char	*ft_reserve(char *reserve, int fd)
{
	char *buffer;
	int byte_read;

	byte_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));

	if (!buffer)
	{
		ft_free(reserve);
		return (NULL);
	}
	while (byte_read > 0)
	{
		byte_read = read(fd ,buffer, BUFFER_SIZE);
		if (byte_read == -1)
			return (ft_free(buffer), ft_free(reserve));
		buffer[byte_read] = '\0';
		if (ft_strchr(buffer, '\n'))
		{
			reserve = ft_strjoin(reserve, buffer);
			break;
		}
		if (byte_read == 0)
		{
			ft_free(buffer);
			return (reserve);
		}
		reserve = ft_strjoin(reserve, buffer);
	}
	ft_free(buffer);
	return (reserve);
}

char *ft_result(char *reserve)
{
	char	*result;
	int		i;

	i = 0;
	if (!reserve[i]) 
		return (NULL);
	while (reserve[i] && reserve[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result) 
		return (ft_free(reserve));
	i = 0;
	while (reserve[i] && reserve[i] != '\n')
	{
		result[i] = reserve[i];
		i++;
	}
	if (reserve[i] == '\n')
	{
		result[i] = reserve[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char *ft_new_reserve(char *reserve)
{
	int	i;
	int	j;
	char *new_reserve;
	i = 0;
	if (!reserve[i])
	{
		if (reserve)
			ft_free(reserve);
		return (NULL);
	}
	while (reserve[i] && reserve[i] != '\n')
		i++;
	if (!reserve[i])
		return(ft_free(reserve));
	new_reserve = malloc(sizeof(char) * (ft_strlen(reserve) - i));
	if (!new_reserve ) 
		return (ft_free(reserve));
	i++;
	j = 0;
	while (reserve[i])
		new_reserve[j++] = reserve[i++];
	//system("leaks a.out");
	new_reserve[j] = '\0';
	ft_free(reserve);
	return (new_reserve);
}

char *get_next_line(int fd)
{
    static char	*reserve;
	char		*line;

	line = NULL;
	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	reserve = ft_reserve(reserve, fd);
	if (!reserve)
		return (NULL);
	line = ft_result(reserve);
	reserve = ft_new_reserve(reserve);
	return (line);
}



//int main()
//{
//	char *str = NULL;
//	int fd;

//	fd = open("exemple.txt", O_RDONLY);
//	while (1)
//	{
//		str = get_next_line(fd);
//		//printf("\nline finale :%s", str);
//		if (str == NULL)
//			break;
//		free(str);
//		str = NULL;
//	}
//	if (str)
//		free(str);

//	close(fd);
//	return (0);
//}