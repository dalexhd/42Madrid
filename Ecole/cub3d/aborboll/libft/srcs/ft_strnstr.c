/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:55 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 11:00:51 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (i < len && haystack[i] != '\0')
	{
		c = 0;
		while (needle[c] == haystack[i + c] && i + c < len)
		{
			if (needle[c + 1] == '\0')
				return ((char*)haystack + i);
			c++;
		}
		i++;
	}
	return (0);
}
