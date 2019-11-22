/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwhat_calculator.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 13:47:36 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 13:55:55 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWHAT_CALCULATOR_H
# define NETWHAT_CALCULATOR_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

char	*ft_itoa(int n);
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*nt_strrchr_modified(const char *s, int c);
void    ft_putchar(char c);

#endif