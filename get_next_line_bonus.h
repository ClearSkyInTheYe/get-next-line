/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chfederi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 04:30:06 by chfederi          #+#    #+#             */
/*   Updated: 2021/12/12 04:30:10 by chfederi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include<stdlib.h>
# include<unistd.h>
# include<limits.h>
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
char	*ft_calloc(size_t n, size_t size );

#endif