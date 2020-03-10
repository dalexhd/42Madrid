/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:42 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/11 22:54:15 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** @author	aborboll
** @param	{int c}	The character
** @desc	Check if it's printable
** @returns	t_bool
*/

t_bool	ft_isprint(int c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}
