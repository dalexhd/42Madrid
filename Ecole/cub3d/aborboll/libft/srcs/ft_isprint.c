/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:41:42 by aborboll          #+#    #+#             */
/*   Updated: 2020/09/05 10:08:18 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** @author	aborboll
** @param	{int c}	The character
** @desc	Check if it's printable
** @returns	t_bool
*/

t_bool	ft_isprint(int c)
{
	if (c < ' ' || c > '~')
		return (FALSE);
	else
		return (TRUE);
}
