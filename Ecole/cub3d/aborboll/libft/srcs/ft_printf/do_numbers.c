/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:44:29 by aborboll          #+#    #+#             */
/*   Updated: 2020/03/10 15:53:32 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static	void	apply_precision(t_info *info)
{
	int		len;
	char	*tmp;

	if (ft_strcmp(info->res, "0") == 0)
		info->flags[F_Argv0] = 1;
	if (info->precision > (len = ft_strlen(info->res)))
	{
		while (info->precision > len)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
	}
	if (info->precision == 0 && info->flags[F_Argv0])
	{
		tmp = info->res;
		info->res = ft_strdup("\0");
		ft_strdel(&tmp);
	}
}

void			apply_flags(t_info *info, int isneg)
{
	if (!isneg)
	{
		if (info->flags[F_Space] && !info->flags[F_Plus] && info->type != 'u')
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
		if (info->flags[F_Plus] && info->type != 'u')
			info->res = ft_strjoin_free(ft_strdup("+"), info->res);
	}
	else
		info->res = ft_strjoin_free(ft_strdup("-"), info->res);
	if (info->flags[F_Hash] && ft_strcmp(info->res, "0") && info->type != 'o')
		info->res = ft_strjoin_free(
			ft_strdup(info->type == 'X' ? "0X" : "0x"), info->res);
}

void			apply_width(t_info *info, int isneg, int len)
{
	if (info->width > len)
	{
		while (info->flags[F_Neg] && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		if (info->flags[F_Zero] && !info->flags[F_Neg] &&
		(info->flags[F_Plus] || info->flags[F_Space] || isneg)
		&& info->precision < 0)
			len += 1;
		while (info->flags[F_Zero] && len < info->width && info->precision < 0)
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
	if (info->flags[F_Zero] && !info->flags[F_Neg] && info->precision < 0)
		apply_flags(info, isneg);
}

void			do_number(t_info *info, int neg)
{
	if (info->type == 'u' && info->length[L_longlong])
		info->res = ft_utoabase((t_ullong)va_arg(info->args[0], t_ullong), 10);
	else if (info->length[L_longlong])
		info->res = ft_itoa_llong((t_llong)va_arg(info->args[0], t_llong));
	else if (info->length[L_long])
		info->res = ft_itoa_long((t_long)va_arg(info->args[0], t_long));
	else if (info->length[L_ulong])
		info->res = ft_itoa_ullong((t_ulong)va_arg(info->args[0], t_ulong));
	else if (info->length[L_char] && info->type == 'u')
		info->res = ft_itoa((t_uchar)va_arg(info->args[0], int));
	else if (info->length[L_char])
		info->res = ft_itoa((t_schar)va_arg(info->args[0], int));
	else if (info->length[L_short] && info->type == 'u')
		info->res = ft_itoa((t_ushsort)va_arg(info->args[0], int));
	else if (info->length[L_short])
		info->res = ft_itoa((short)va_arg(info->args[0], int));
	else if (info->type == 'u')
		info->res = ft_utoabase((t_ullong)va_arg(info->args[0], t_uint), 10);
	else
		info->res = ft_itoa(va_arg(info->args[0], int));
	neg = apply_negative(info);
	apply_precision(info);
	if (!info->flags[F_Zero] || info->flags[F_Neg] || info->precision >= 0)
		apply_flags(info, neg);
	apply_width(info, neg, ft_strlen(info->res));
}
