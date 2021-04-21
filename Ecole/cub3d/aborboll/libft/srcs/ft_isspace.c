/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 14:14:46 by aborboll          #+#    #+#             */
/*   Updated: 2020/09/05 10:08:11 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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
		return (TRUE);
	return (FALSE);
}
