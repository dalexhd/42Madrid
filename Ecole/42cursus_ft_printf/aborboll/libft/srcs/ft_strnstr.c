/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:55 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 21:49:52 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	c;
	char	*str;

	if (needle[0] == '\0' || needle == NULL)
		return ((char*)haystack);
	i = 0;
	str = ft_strnew(len);
	while (haystack[i] != '\0' && i < len)
	{
		c = 0;
		while (needle[c] == haystack[i + c] && i + c < len)
		{
			if (needle[c + 1] == '\0')
			{
				return ((char*)haystack + i);
			}
			c++;
		}
		i++;
	}
	return (0);
}
