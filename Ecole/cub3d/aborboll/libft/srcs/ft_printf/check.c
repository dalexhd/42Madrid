/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:15:13 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	check_flags(t_info *info)
{
	while (is_flag(info->str[0][0]))
	{
		if (info->str[0][0] == '-')
			info->flags[F_Neg] = 1;
		else if (info->str[0][0] == '+')
			info->flags[F_Plus] = 1;
		else if (info->str[0][0] == ' ')
			info->flags[F_Space] = 1;
		else if (info->str[0][0] == '*')
			info->flags[F_Star] = 1;
		else if (info->str[0][0] == '0')
			info->flags[F_Zero] = 1;
		else if (info->str[0][0] == '#')
			info->flags[F_Hash] = 1;
		(info->str[0])++;
	}
}

void	check_type(t_info *info)
{
	if (is_type(info->str[0][0]))
	{
		info->type = info->str[0][0];
	}
}

void	check_width(t_info *info)
{
	int	num;

	while (is_width(info->str[0][0]))
	{
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->width = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->width = va_arg(info->args[0], int);
			(info->str[0])++;
		}
	}
	if (info->flags[F_Star])
	{
		num = va_arg(info->args[0], int);
		if (num < 0)
			info->flags[F_Neg] = 1;
		info->width = ft_abs(num);
	}
}

void	check_for_lengths(t_info *info)
{
	if (is_length(info->str[0][0]))
	{
		if (info->str[0][0] == 'l' && info->str[0][1] == 'l')
		{
			info->length[L_longlong] = 1;
			(info->str[0])++;
		}
		else if (info->str[0][0] == 'l' && info->str[0][1] == 'u')
			info->length[L_ulong] = 1;
		else if (info->str[0][0] == 'l')
			info->length[L_long] = 1;
		else if (info->str[0][0] == 'h' && info->str[0][1] == 'h')
		{
			info->length[L_char] = 1;
			(info->str[0])++;
		}
		else if (info->str[0][0] == 'h')
			info->length[L_short] = 1;
		else if (info->str[0][0] == 'z')
			info->length[L_size] = 1;
		(info->str[0])++;
		if (is_length(info->str[0][0]))
			reinit_lengths(info);
	}
}

void	check_for_precision(t_info *info)
{
	while (is_precision(info->str[0][0]))
	{
		(info->str[0])++;
		if (info->str[0][0] >= '0' && info->str[0][0] <= '9')
		{
			info->precision = ft_atoi(info->str[0]);
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
		else if (info->str[0][0] == '*')
		{
			info->precision = va_arg(info->args[0], int);
			(info->str[0])++;
		}
		else if (info->str[0][0] != '-')
			info->precision = 0;
		else
		{
			(info->str[0])++;
			while (info->str[0][0] >= '0' && info->str[0][0] <= '9')
				(info->str[0])++;
		}
	}
}
