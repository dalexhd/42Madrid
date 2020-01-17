/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 18:43:19 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/17 15:30:49 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>


void	print(t_info *info)
{
	int i;

	i = 0;
	while (info->res[i])
	{
		ft_putchar(info->res[i]);
		i++;
	}
	info->count += i;
}

void	check_and_print(t_info *info)
{
	(info->str[0])++;
	check_flags(info);
	check_width(info);
	check_for_precision(info);
	check_for_lengths(info);
	check_type(info);

	if (info->type)
	{
		if (info->type == 's')
			do_string(info);
		if (info->type == 'i' || info->type == 'd' || info->type == 'u' || info->type == 'o')
			do_number(info);
		else if (info->type == 'x' || info->type == 'X')
			do_hexadecimal(info);
		else if (info->type == 'c')
			do_char(info);
		else if (info->type == 'p')
			do_address(info);
		else if (info->type == '%')
			do_percentage(info);
		print(info);
	}
/* 	debug(info); */
	reinit(info);
}

int	ft_printf(char *format, ...)
{
	va_list args;
	int		result;
	t_info	*info;

	result = 0;
	if (!(info = (t_info*)malloc(sizeof(t_info))) || !(format))
		return (EXIT_FAILURE);
	va_start(args, format);
	init_struct(info, &format, &args);
	result = info->count;
	while (info->str[0][0])
	{
		if (info->str[0][0] != '%')
		{
			ft_putchar(info->str[0][0]);
			(info->str[0])++;
			info->count++;
		}
		else
			check_and_print(info);
	}
	result = info->count;
	free(info);
	va_end(args);
	return (result);
}
