/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:43:02 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/16 17:22:05 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*new;

	if (!s)
		return (0);
	if (ft_strlen(s) < start)
		return ((char*)ft_calloc(start * sizeof(char), len));
	s += start;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	ft_strlcpy(new, s, len + 1);
	return (new);
}
