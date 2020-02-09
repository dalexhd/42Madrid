/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 15:29:52 by aborboll          #+#    #+#             */
/*   Updated: 2020/02/08 17:14:19 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_struct(t_info *info, char **str, va_list *args)
{
	int	i;

	i = 0;
	while (i++ < N_FLAGS)
		info->flags[i] = 0;
	i = 0;
	while (i < N_LENS)
		info->length[i++] = 0;
	info->args = args;
	info->str = str;
	info->count = 0;
	info->width = -1;
	info->precision = -1;
	info->type = '\0';
	info->res = NULL;
}

void	reinit_lengths(t_info *info)
{
	int	i;

	i = 0;
	while (i++ < N_LENS)
		info->length[i] = 0;
}

void	reinit(t_info *info)
{
	int	i;

	i = 0;
	while (i < N_FLAGS)
	{
		info->flags[i] = 0;
		i++;
	}
	i = 0;
	while (i < N_LENS)
		info->length[i++] = 0;
	info->width = -1;
	info->precision = -1;
	info->type = '\0';
	if (info->res != NULL)
		ft_strdel(&info->res);
}
