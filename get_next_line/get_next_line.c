#include "get_next_line.h"

char	*read_line(char *str)
{
	int		sayaciki;
	int		sayac;
	char	*yeni_str;

	sayaciki = 0;
	sayac = 0;
	while (str[sayac] && str[sayac] != '\n')
		sayac++;
	yeni_str = malloc(sizeof(char) * (ft_strlen(str) - sayac));
	sayac++; //newline ı atla
	while (str[sayac])
	{
		yeni_str[sayaciki] = str[sayac];
		sayaciki++;
		sayac++;
	}
	yeni_str[sayaciki] = '\0';
	free(str); //static olarak tutulan eski deger silinir.
	return (yeni_str); //yeni static degiskene aktarilmak üzere geri döner.
}

char	*nextline(char *str)
{
	int		sayac;
	char	*yeni_str;

	sayac = 0;
	while (str[sayac] != '\n' && str[sayac] != '\0')
		sayac++; //ayirman gereken karakter sayisi
	yeni_str = malloc(sizeof(char) * sayac + 2);
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
	yeni_str[sayac] = '\0'; //yeni satira kadar olan string
	return (yeni_str);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*s;
	int			readss;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	buff = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	readss = 1;
	while (!ft_strchr(buff, '\n') && readss != 0)
	{
		readss = read(fd, buff, BUFFER_SIZE);
		if (readss < 0)
		{
			free(buff);
			return (line);
		}
		buff[readss] = '\0';
		line = ft_strjoin(line, buff); //satir boşsa ilk olarak mallocla boş string yap
	}
	//free(buff);
	s = nextline(line);
	line = read_line(line);
	return (s);
}

int main()
{
	int	fd;

	fd = open("my.txt",O_RDONLY);
	char *s = get_next_line(fd);
	int	i;

	i = 0;
	while (i < 80)
	{
		printf("%s", s);
		s = get_next_line(fd);
		i++;
	}
}
