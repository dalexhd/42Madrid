/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:57:33 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/06 22:19:09 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int c;

	if (needle[0] == '\0')
		return ((char*)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		c = 0;
		while (needle[c] == haystack[i + c])
		{
			if (needle[c + 1] == '\0')
			{
				return (char*)(haystack + i);
			}
			c++;
		}
		i++;
	}
	return (0);
}
