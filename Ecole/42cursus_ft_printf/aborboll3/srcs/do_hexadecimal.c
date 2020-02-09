/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:14:57 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/22 19:38:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	apply_precision(t_info *info)
{
	int len;

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
	if (info->precision == 0)
		info->res = ft_strdup("\0");
}

static	void	apply_width(t_info *info)
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
				(info->flags[F_Plus] == 1 || info->flags[F_Space] == 1) &&
					info->precision < 0)
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

static	void	apply_flags(t_info *info)
{
	if (info->flags[F_Hash] == 1 && !info->flags[F_Argv0] && info->type != 'o')
		info->res = ft_strjoin_free(
			ft_strdup(info->type == 'X' ? "0X" : "0x"), info->res);
}

void			do_hexadecimal(t_info *info)
{
	char *str;

	str = "";
	if (info->type == 'x')
	{
		str = ft_utoabase((t_ulong)va_arg(info->args[0], t_ulong), 16);
		info->res = ft_strto(str, ft_tolower);
	}
	else if (info->type == 'X')
	{
		str = ft_utoabase((t_ulong)va_arg(info->args[0], t_ulong), 16);
		info->res = ft_strto(str, ft_toupper);
	}
	free(str);
	apply_precision(info);
	apply_flags(info);
	apply_width(info);
}
