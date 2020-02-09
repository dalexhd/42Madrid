/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:42:23 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/22 19:17:15 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if ((s1 == NULL || s2 == NULL) ||
		!(str = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (0);
	return (ft_strcat(ft_strcpy(str, s1), s2));
}
