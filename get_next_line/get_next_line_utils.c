#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		a;
	char	*dizi;

	i = 0;
	a = 0;;
	if (!s1)
	{
		s1 = (char *)malloc(1);
		s1[0] = '\0';
	}
	dizi = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dizi)
		return (0);
	while (s1[i] != '\0')
	{
		dizi[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		dizi[i] = s2[a];
		i++;
		a++;
	}
	dizi[i] = '\0';
	free (s1);
	return (dizi);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	size_t	a;

	a = ft_strlen(s);
	i = 0;
	while (i <= a)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t	a;

	a = 0;
	while (s[a] != '\0')
	{
		a++;
	}
	return (a);
}
