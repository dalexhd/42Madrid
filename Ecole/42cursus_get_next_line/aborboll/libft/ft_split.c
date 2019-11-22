/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:14 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/10 20:28:43 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c)
{
	t_uint	i;
	t_uint	j;
	char	**words;

	if (s == NULL ||
		!(words = (char**)malloc(sizeof(char*) * (ft_countwords(s, c) + 1))))
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		i = 0;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i > 0)
		{
			words[j++] = ft_strncpy(ft_strnew(i), s, i);
			s = &s[i];
		}
		else
			s++;
	}
	words[j] = NULL;
	return (words);
}
