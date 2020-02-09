/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:14:57 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/08 17:50:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		apply_hash(t_info *info, int flag, int iszero)
{
	t_bool a;

	a = iszero;
	if (info->flags[F_Hash] && iszero != 1)
	{
		if (info->flags[F_Zero] && !info->flags[F_Neg] &&
		flag && info->precision < 0)
			info->res = ft_strjoin_free(
				ft_strdup(info->type == 'X' ? "0X" : "0x"), info->res);
		else if ((((!info->flags[F_Zero] || info->flags[F_Neg]) && !flag) ||
		(info->flags[F_Zero] && info->precision > 0 && !flag)))
			info->res = ft_strjoin_free(
				ft_strdup(info->type == 'X' ? "0X" : "0x"), info->res);
	}
}

static	void	apply_width(t_info *info, int iszero, int len)
{
	if (info->width > len)
	{
		while (info->flags[F_Neg] && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		if (info->flags[F_Zero] && !info->flags[F_Neg] &&
				info->flags[F_Hash] && info->precision < 0 && !iszero)
			len += 2;
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
	apply_hash(info, 1, iszero);
}

static	void	apply_precision(t_info *info, int iszero)
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
	if (info->precision == 0 && iszero == 1)
	{
		free(info->res);
		info->res = ft_strdup("");
	}
	apply_hash(info, 0, iszero);
	apply_width(info, iszero, ft_strlen(info->res));
}

void			do_hexadecimal(t_info *info)
{
	if (info->length[L_long])
		info->res = ft_utoabase((t_long)va_arg(info->args[0], t_long), 16);
	else if (info->length[L_longlong])
		info->res = ft_utoabase((t_llong)va_arg(info->args[0], t_llong), 16);
	else if (info->length[L_ulong])
		info->res = ft_utoabase((t_ulong)va_arg(info->args[0], t_ulong), 16);
	else
		info->res = ft_utoabase((t_uint)va_arg(info->args[0], t_uint), 16);
	if (info->type == 'x' || info->type == 'X')
		ft_strto(info->res, info->type == 'X' ? ft_toupper : ft_tolower);
	apply_precision(info, ft_strcmp(info->res, "0") == 0);
}
