#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4
# endif

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>

char *get_next_line(int fd);
char *nextline(char *str);
char *read_line(char *str);
char *put_line(int fd, char *line);

char *ft_strchr(const char *s, int c);
char *ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
#endif
