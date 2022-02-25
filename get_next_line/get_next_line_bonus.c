/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysensoy <ysensoy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 11:00:52 by ysensoy           #+#    #+#             */
/*   Updated: 2022/02/25 17:51:20 by ysensoy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*newlinedansonra_line(char *str)
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
	yeni_str = (char *)malloc(sizeof(char) * ((ft_strlen(str) - sayac) + 1));
	if (!yeni_str)
		return (NULL);
	sayac++;
	while (str[sayac])
		yeni_str[sayaciki++] = str[sayac++];
	yeni_str[sayaciki] = '\0';
	free(str);
	return (yeni_str);
}

char	*newlinedanonce_line(char *str)
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

char	*putline(int fd, char *line)
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
	static char	*line[4096];
	char		*s;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line[fd] = putline(fd, line[fd]);
	if (line[fd])
	{
		s = newlinedanonce_line(line[fd]);
		line[fd] = newlinedansonra_line(line[fd]);
		return (s);
	}
	return (NULL);
}
/*
int main()
{
    int fd = open("my.txt", O_RDONLY);
    int fd_ = open("my2.txt", O_RDONLY);
    int fd1 = open("my3.txt", O_RDONLY);
    int fd1_ = open("my4.txt", O_RDONLY);
    int i;
	int fd_arry[4];
	fd_arry[0] = fd;
	fd_arry[1] = fd_;
	fd_arry[2] = fd1;
	fd_arry[3] = fd1_;
    char    **str;
    str = (char **)malloc(sizeof(char*) * 15);
    while (i < 4)
    {
		str[i] = get_next_line(fd_arry[i]);
        while(str[i])
		{
			write(1, str[i], ft_strlen(str[i]));
			str[i] = get_next_line(fd_arry[i]);
		}
		i++;
    }
}
*/
