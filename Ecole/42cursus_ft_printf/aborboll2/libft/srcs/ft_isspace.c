/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:14:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 22:54:15 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @author	aborboll
** @param	{int c}	The character
** @desc	Check if it's an spacer
** @returns	t_bool
*/

t_bool	ft_isspace(int c)
{
	if (c == ' ' ||
		c == '\n' ||
		c == '\t' ||
		c == '\r' ||
		c == '\f' ||
		c == '\v')
		return (1);
	return (0);
}
