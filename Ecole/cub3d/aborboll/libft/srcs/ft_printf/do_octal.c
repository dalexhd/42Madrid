/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 05:44:29 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void		apply_hash(t_info *info, int flag, int iszero)
{
	if (info->flags[F_Hash] && iszero != 1)
	{
		if (((!info->flags[F_Zero] || info->flags[F_Neg]) &&
		!flag) || (info->flags[F_Zero] && info->precision > 0 && !flag))
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
	}
}

static	void	apply_precision(t_info *info, int iszero)
{
	int len;

	apply_hash(info, 0, iszero);
	if (info->precision > (len = ft_strlen(info->res)))
	{
		while (info->precision > len)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
	}
	if (!info->precision && iszero && !info->flags[F_Hash])
		info->res = ft_strdup("");
}

static	void	apply_width(t_info *info, int isneg, int iszero)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
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
	apply_hash(info, 1, iszero);
}

static	void	apply_flags(t_info *info, int isneg)
{
	if (!isneg)
	{
		if (info->flags[F_Space] && !info->flags[F_Plus])
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
	}
	else
		info->res = ft_strjoin_free(ft_strdup("-"), info->res);
	if (info->flags[F_Plus] && info->res[0] != '-')
		info->res = ft_strjoin_free(ft_strdup("+"), info->res);
}

void			do_octal(t_info *info)
{
	int		neg;
	int		iszero;

	if (info->length[L_long])
		info->res = ft_utoabase((t_long)va_arg(info->args[0], t_long), 8);
	else if (info->length[L_longlong])
		info->res = ft_utoabase((t_llong)va_arg(info->args[0], t_llong), 8);
	else if (info->length[L_ulong])
		info->res = ft_utoabase((t_ulong)va_arg(info->args[0], t_ulong), 8);
	else
		info->res = ft_utoabase((t_uint)va_arg(info->args[0], t_uint), 8);
	iszero = 0;
	if (ft_strcmp(info->res, "0") == 0)
		iszero = 1;
	neg = apply_negative(info);
	apply_precision(info, iszero);
	if (!info->flags[F_Zero] || info->flags[F_Neg] || info->precision > 0)
		apply_flags(info, neg);
	apply_width(info, neg, iszero);
	if (info->flags[F_Zero] && !info->flags[F_Neg] && info->precision < 0)
		apply_flags(info, neg);
}
