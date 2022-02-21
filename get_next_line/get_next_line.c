/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42kocaeli.com.tr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:27:42 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/21 17:26:21 by ysensoy          ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_line(char *str)
{
	int		sayaciki;
	int		sayac;
	char	*yeni_str;

	sayac = 0;
	while (str[sayac] && str[sayac] != '\n')
		sayac++;
	if (!str[sayac])
	{
		free(str);
		return (NULL);
	}
	yeni_str = malloc(sizeof(char) * (ft_strlen(str) - sayac));
	if (!yeni_str)
		return (NULL);
	sayac++;
	sayaciki = 0;
	while (str[sayac])
	{
		yeni_str[sayaciki] = str[sayac];
		sayaciki++;
		sayac++;
	}
	yeni_str[sayaciki] = '\0';
	free(str);
	return (yeni_str);
}

char	*nextline(char *str)
{
	int		sayac;
	char	*yeni_str;

	sayac = 0;
	while (str[sayac] != '\n' && str[sayac] != '\0')
		sayac++;
	yeni_str = malloc(sizeof(char) * (sayac + 2));
	if (!yeni_str)
		return (0);
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

	buff = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readss = read(fd, buff, BUFFER_SIZE);
	while (readss != 0)
	{
		if (readss < 0)
		{
			free(buff);
			return (NULL);
		}
		buff[readss] = '\0';
		line = ft_strjoin(line, buff);
		readss = read(fd, buff, BUFFER_SIZE);
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
	return (0);
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
