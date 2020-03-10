/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 19:41:21 by aborboll          #+#    #+#             */
/*   Updated: 2020/03/10 15:53:36 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		apply_precisison(t_info *info)
{
	if (info->precision < (int)ft_strlen(info->res))
		info->res[info->precision] = '\0';
}

static void		apply_width(t_info *info)
{
	int len;

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] && info->width > len)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		while (info->flags[F_Zero] && info->width > len)
		{
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
			len++;
		}
		while (info->width > len)
		{
			info->res = ft_strjoin_free(ft_strdup(" "), info->res);
			len++;
		}
	}
}

void			do_string(t_info *info)
{
	char	*sarg;

	if ((sarg = va_arg(info->args[0], char*)))
		info->res = ft_strdup(sarg);
	else
		info->res = ft_strdup("(null)");
	if (info->precision >= 0)
		apply_precisison(info);
	if (info->width > 0)
		apply_width(info);
}
