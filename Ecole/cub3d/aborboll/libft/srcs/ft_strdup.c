/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:20 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/08 17:33:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	if (s1 == NULL)
		return (0);
	i = ft_strlen(s1);
	if (!(str = (char *)malloc(sizeof(*s1) * (i + 1))))
		return (NULL);
	ft_memcpy(str, s1, i);
	str[i++] = '\0';
	return (str);
}
