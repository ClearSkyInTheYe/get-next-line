/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 20:43:18 by chfederi          #+#    #+#             */
/*   Updated: 2021/11/15 20:43:22 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdlib.h>
# include<unistd.h>
# include<stdint.h>

char	*ft_cpy(size_t b, char *str, char *s);
char	*get_next_line(int fd);
char	*ft_strdup(const char *s1);
char	*ft_strchr(const char	*str, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*trstr(char *s);
char	*tail(char *s );
char	*myread(int fd, char *s);
size_t	ft_strlen(const char *str);
char	*ft_calloc(size_t count, size_t size);
//void	*ft_memset(void *m, int v, size_t l);

#endif
