/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 13:50:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/30 23:15:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>
# include <strings.h>
# include <limits.h>
# include <fcntl.h>

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;
typedef int				t_bool;

int		get_next_line(int fd, char **line);
char	*ft_substr(char const *s, t_uint start, size_t len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strchr(const char *s, int c);
size_t	ft_return(char **cache, char **line, int fd, int ret);
int		ft_new_line(char **cache, char **line, int fd);

#endif
