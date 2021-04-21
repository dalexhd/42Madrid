/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strevery.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 16:27:22 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/08 21:28:03 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool	ft_strevery(char const *s, t_bool (*f)(int))
{
	size_t	i;

	i = -1;
	while (++i < ft_strlen(s))
	{
		if (!f(s[i]))
			return (FALSE);
	}
	return (TRUE);
}
