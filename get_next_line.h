#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

//# define BUFFER_SIZE 1

char			*get_next_line(int fd);
size_t			ft_strlen(const	char *str);
char	*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
void *ft_free(char *str);

#endif
