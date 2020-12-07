/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:36 by aborboll          #+#    #+#             */
/*   Updated: 2020/09/05 10:08:30 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** @author	aborboll
** @param	{int c}	The character
** @desc	Check if it's ascii character
** @returns	t_bool
*/

t_bool	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (TRUE);
	return (FALSE);
}
