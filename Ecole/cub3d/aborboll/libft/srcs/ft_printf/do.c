/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:34:09 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	do_char(t_info *info)
{
	int		len;
	char	sarg;

	info->res = ft_strnew(1);
	if ((sarg = (char)va_arg(info->args[0], int)))
		info->res[0] = sarg;
	else
	{
		info->flags[F_Trash] = 1;
		info->count += 1;
	}
	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] && len++ < info->width)
			info->res = ft_strjoin_free(
				info->res, ft_strdup(len + 1 == info->width &&
				info->flags[F_Trash] ? "" : " "));
		while (info->flags[F_Zero] && len++ < info->width)
			info->res = ft_strjoin_free(ft_strdup("0"), info->res);
		while (len++ < info->width)
			info->res = ft_strjoin_free(
				ft_strdup(len + 1 == info->width &&
				info->flags[F_Trash] ? "" : " "), info->res);
	}
}

void	do_percentage(t_info *info)
{
	int		len;

	info->res = ft_strdup("%");
	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		while (info->flags[F_Zero] && len < info->width)
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
