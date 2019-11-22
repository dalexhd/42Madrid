/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:43:02 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 22:02:09 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, t_uint start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == '\0')
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len)
		new[i++] = s[start++];
	new[i] = '\0';
	return (new);
}
