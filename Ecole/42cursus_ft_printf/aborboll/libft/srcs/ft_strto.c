/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strto.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 21:56:24 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/11 22:05:43 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strto(char *str, int (*f)(int))
{
	char	*new;
	int		i;

	new = ft_strnew(ft_strlen(str));
	i = 0;
	while (str[i])
	{
		new[i] = f(str[i]);
		++i;
	}
	new[i] = '\0';
	return (new);
}
