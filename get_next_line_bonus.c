/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 04:31:28 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/12 04:31:31 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

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

	if (read (fd, (void *)0, 0) != 0 || BUFFER_SIZE <= 0)
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
	static char	*s[OPEN_MAX] = {NULL};
	char		*st;
	char		*tmp;

	if (s[fd] == NULL || !ft_strchr(s[fd], '\n'))
	{
		s[fd] = myread(fd, s[fd]);
		if (s[fd] == NULL)
			return (NULL);
		st = trstr(s[fd]);
		tmp = tail(s[fd]);
		free(s[fd]);
		s[fd] = tmp;
		return (st);
	}
	if (s[fd] != NULL)
	{
		st = trstr(s[fd]);
		tmp = tail(s[fd]);
		free(s[fd]);
		s[fd] = tmp;
		return (st);
	}
	return (NULL);
}
