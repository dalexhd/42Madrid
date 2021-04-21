/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 11:45:01 by mbrunel           #+#    #+#             */
/*   Updated: 2021/02/09 18:15:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef LIBASM_H
# define LIBASM_H

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s1);
int			ft_strcmp(const char *s1, const char *s2);
size_t		ft_read(int fildes, void *buf, size_t nbyte);
size_t		ft_write(int fildes, const void *buf, size_t nbyte);
char		*ft_strcpy(char *dst, const char *src);

#endif
