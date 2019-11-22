/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:59 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 22:03:13 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	len;
	char	*str;

	if (s1 == '\0' || set == '\0')
		return (0);
	i = 0;
	while (s1[i] != '\0' && ft_strchr(set, s1[i]) != NULL)
		i++;
	len = ft_strlen(&s1[i]);
	if (len)
		while (s1[i + len - 1] && ft_strchr(set, s1[i + len - 1]) != NULL)
			len--;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str = ft_strncpy(str, &s1[i], len);
	str[len] = '\0';
	return (str);
}
