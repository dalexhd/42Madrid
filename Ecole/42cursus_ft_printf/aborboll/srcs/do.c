/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:34:09 by aborboll          #+#    #+#             */
/*   Updated: 2020/01/12 17:08:55 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	do_char(t_info *info)
{
	int		len;
	char	sarg;

	info->res = ft_strnew(1);
	if ((sarg = va_arg(info->args[0], int)))
		info->res[0] = sarg;
	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] == 1 && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		while (info->flags[F_Zero] == 1 && len < info->width)
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

void	do_percentage(t_info *info)
{
	int		len;

	info->res = ft_strdup("%");

	if (info->width > (len = ft_strlen(info->res)))
	{
		while (info->flags[F_Neg] == 1 && len < info->width)
		{
			info->res = ft_strjoin_free(info->res, ft_strdup(" "));
			len++;
		}
		while (info->flags[F_Zero] == 1 && len < info->width)
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

