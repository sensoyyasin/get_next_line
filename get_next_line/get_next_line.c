/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:27:42 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/22 16:57:33 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str)
{
	int		sayac;
	int		sayaciki;
	char	*yeni_str;

	sayac = 0;
	sayaciki = 0;
	while (str[sayac] && str[sayac] != '\n')
		sayac++;
	if (!str[sayac])
	{
		free(str);
		return (NULL);
	}
	yeni_str = (char *)malloc(sizeof(char) * (ft_strlen(str) - sayac + 1));
	if (!yeni_str)
		return (NULL);
	sayac++;
	while (str[sayac])
		yeni_str[sayaciki++] = str[sayac++];
	yeni_str[sayaciki] = '\0';
	free(str);
	return (yeni_str);
}

char	*nextline(char *str)
{
	int		sayac;
	char	*yeni_str;

	sayac = 0;
	if (!str[sayac])
		return (NULL);
	while (str[sayac] != '\n' && str[sayac] != '\0')
		sayac++;
	yeni_str = (char *)malloc(sizeof(char) * (sayac + 2));
	if (!yeni_str)
		return (NULL);
	sayac = 0;
	while (str[sayac] && str[sayac] != '\n')
	{
		yeni_str[sayac] = str[sayac];
		sayac++;
	}
	if (str[sayac] == '\n')
	{
		yeni_str[sayac] = str[sayac];
		sayac++;
	}
	yeni_str[sayac] = '\0';
	return (yeni_str);
}

char	*put_line(int fd, char *line)
{
	char	*buff;
	int		readss;

	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readss = 1;
	while (!ft_strchr(line, '\n') && readss != 0)
	{
		readss = read(fd, buff, BUFFER_SIZE);
		if (readss == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[readss] = '\0';
		line = ft_strjoin(line, buff);
	}
	free(buff);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = put_line(fd, line);
	if (line)
	{
		s = nextline(line);
		line = read_line(line);
		return (s);
	}
	return (NULL);
}
/*
int	main(void)
{
	int		fd;
	char	*s;
	int		i;

	fd = open("my.txt", O_RDONLY);
	s = get_next_line(fd);
	i = 0;
	while (s)
	{
		printf("%s", s);
		s = get_next_line(fd);
		i++;
	}
}*/
