/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:15:13 by aborboll          #+#    #+#             */
/*   Updated: 2020/03/10 15:53:45 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_bool	is_type(char c)
{
	if (c == '%' || c == 's' || c == 'S' || c == 'p' || c == 'd' ||
			c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' ||
			c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' ||
			c == 'P' || c == 'b' || c == 'I' || c == 'B')
		return (true);
	return (false);
}

t_bool	is_width(char c)
{
	if ((c >= '0' && c <= '9') || c == '*')
		return (true);
	return (false);
}

t_bool	is_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '#' || c == '0' || c == '*')
		return (true);
	return (false);
}

t_bool	is_precision(char c)
{
	if (c == '.')
		return (true);
	return (false);
}

t_bool	is_length(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z')
		return (true);
	return (false);
}
