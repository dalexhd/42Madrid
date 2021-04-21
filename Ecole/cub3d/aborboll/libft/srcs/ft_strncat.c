/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:49:12 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 11:00:23 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	z;

	i = ft_strlen(s1);
	z = 0;
	while (z < n && s2[z] != '\0')
	{
		s1[z + i] = s2[z];
		z++;
	}
	s1[i + z] = '\0';
	return (s1);
}
