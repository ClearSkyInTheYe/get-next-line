/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:42:40 by chfederi          #+#    #+#             */
/*   Updated: 2021/11/15 20:42:45 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*trstr(char *s)
{
	char	*str;
	size_t	i;
	size_t	x;

	i = 0;
	x = 0;
	while (s[i] && s[i] != '\n')
		i++;
	str = malloc(sizeof (char ) * (i + 2));
	if (str == NULL)
		return (NULL);
	i = i + 1;
	while (i > 0)
	{
		str[x] = s[x];
		i--;
		x++;
	}
	str[x] = '\0';
	return (str);
}

char	*tail(char *s )
{
	char	*str;
	size_t	i;
	size_t	x;
	size_t	b;

	if (s == NULL)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	b = i + 1;
	if (s[i] == '\0')
		b = i;
	if (s[i] == '\n' && s[i + 1] == '\0')
		return (NULL);
	x = 0;
	while (s[i++])
		x++;
	if (x == 0)
		return (NULL);
	str = malloc(sizeof (char ) * (x + 1));
	if (str == NULL)
		return (NULL);
	str = ft_cpy(b, str, s);
	return (str);
}

char	*ft_cpy(size_t b, char *str, char *s)
{
	size_t	x;

	x = 0;
	while (s[b])
		str[x++] = s[b++];
	str[x] = '\0';
	return (str);
}

char	*myread(int fd, char *s)
{
	char		*str;
	size_t		l;
	char		*tmp;

	if (read (fd, NULL, 0) != 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str = ft_calloc((BUFFER_SIZE + 1), sizeof (char ));
	if (!str)
		return (NULL);
	if (s == NULL || !ft_strchr(s, '\n'))
	{
		while (!ft_strchr(str, '\n'))
		{
			l = read(fd, str, BUFFER_SIZE);
			str[l] = '\0';
			if (l == 0)
				break ;
			tmp = ft_strjoin(s, str);
			free(s);
			s = tmp;
		}
		free(str);
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s = NULL;
	char		*st;
	char		*tmp;

	if (s == NULL || !ft_strchr(s, '\n'))
	{
		s = myread(fd, s);
		if (s == NULL)
			return (NULL);
		st = trstr(s);
		tmp = tail(s);
		free(s);
		s = tmp;
		return (st);
	}
	if (s != NULL)
	{
		st = trstr(s);
		tmp = tail(s);
		free(s);
		s = tmp;
		return (st);
	}
	return (NULL);
}

//#include <fcntl.h>
//#include <stdio.h>
//
//int main()
//{
//	int fd = open("123", O_RDONLY);
////	int fd = open("123", O_RDONLY);
//	char *str;
//
//	str = (char*)1;
////	printf("s2 = %zu\n", ft_strlen(get_next_line(fd)));
//	while (str)
//	{
////		write(1, "111\n", 4);
//		str = get_next_line(fd);
////		write(1, str, ft_strlen(str));
//		printf("%s", str);
//		free(str);
////		write(1, "222\n", 4);
//	}
//
////	printf("%s\n", get_next_line(fd));
//}