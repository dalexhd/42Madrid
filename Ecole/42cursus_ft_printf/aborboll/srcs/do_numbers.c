/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:44:29 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/17 16:39:53 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	apply_negative(t_info *info)
{
	char	*tmp;

	if (info->res[0] != '-')
		return (0);
	tmp = info->res;
	if (!(info->res = ft_strdup(++(info->res))))
		return (0);
	free(tmp);
	return (1);
}

static	void	apply_precision(t_info *info)
{
	int len;

	if (info->precision > (len = ft_strlen(info->res)))
	{
		while (info->precision > len)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
	}
	if (info->precision == 0)
		info->res = ft_strdup("\0");
}

void	apply_width(t_info *info, int isneg)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] == 1 && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		if (info->flags[F_Zero] == 1 && info->flags[F_Neg] != 1 &&
				(info->flags[F_Plus] == 1 || info->flags[F_Space] == 1 ||
				isneg == 1) && info->precision < 0)
			len += 1;
		while (info->flags[F_Zero] == 1 && len < info->width &&
				info->precision < 0)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
		while (len < info->width)
		{
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
			len++;
		}
	}
}

void	apply_flags(t_info *info, int isneg)
{
	if (!isneg)
	{
		if (info->flags[F_Space] == 1 && info->flags[F_Plus] != 1)
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
		else if (info->flags[F_Plus] == 1)
			info->res = ft_strjoin_free(ft_strdup("+"), info->res);
	}else{
		info->res = ft_strjoin_free(ft_strdup("-"), info->res);
	}
	if (info->flags[F_Hash] == 1 && ft_strcmp(info->res, "0") && info->type != 'o')
		info->res = ft_strjoin_free(info->type == 'X' ? ft_strdup("0X") : ft_strdup("0x"), info->res);
}

void		do_number(t_info *info)
{
	int		neg;

	if (info->type == 'o')
		info->res = ft_utoabase((t_ulong) va_arg(info->args[0], t_ulong), 8);
	else if (info->length[L_longlong])
		info->res = ft_itoa_llong((t_llong) va_arg(info->args[0], t_llong));
	else if (info->length[L_long])
		info->res = ft_itoa_long((t_long) va_arg(info->args[0], t_long));
	else if (info->length[L_ulong])
		info->res = ft_itoa_ullong((t_ulong) va_arg(info->args[0], t_ulong));
	else if (info->type == 'u')
		info->res = ft_utoabase((t_ullong) va_arg(info->args[0], t_uint), 10);
	else
		info->res = ft_itoa(va_arg(info->args[0], int));
	neg = apply_negative(info);
	apply_precision(info);

	if (info->flags[F_Zero] != 1 || info->flags[F_Neg] == 1 || info->precision > 0)
		apply_flags(info, neg);
	apply_width(info, neg);
	if (info->flags[F_Zero] == 1 && info->flags[F_Neg] != 1 && info->precision < 0)
		apply_flags(info, neg);
}
