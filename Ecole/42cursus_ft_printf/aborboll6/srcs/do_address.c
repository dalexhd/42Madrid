/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_address.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 15:10:59 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/08 17:19:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	void	apply_precision(t_info *info)
{
	int len;

	if (info->precision > (len = ft_strlen(info->res)))
	{
		while (info->precision > len && info->precision > 0)
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

	len = ft_strlen(info->res);
	while (info->flags[F_Neg] && len++ < info->width)
		info->res = ft_strjoin_free(info->res, ft_strdup(" "));
	if (info->flags[F_Zero] && !info->flags[F_Neg])
		len += 1;
	while (info->flags[F_Zero] && len++ < info->width)
		info->res = ft_strjoin_free(ft_strdup("0"), info->res);
	while (len++ < info->width)
		info->res = ft_strjoin_free(ft_strdup(" "), info->res);
}

void			do_address(t_info *info)
{
	void	*arg;

	arg = va_arg(info->args[0], void*);
	if (arg == NULL)
		info->res = ft_strdup("0");
	else
		info->res = ft_utoabase((t_ullong)arg, 16);
	apply_precision(info);
	if (info->flags[F_Zero] && !info->flags[F_Neg])
		apply_width(info);
	info->res = ft_strjoin_free(ft_strdup("0x"), info->res);
	apply_width(info);
	if (info->type == 'P')
		ft_strto(info->res, ft_toupper);
}
