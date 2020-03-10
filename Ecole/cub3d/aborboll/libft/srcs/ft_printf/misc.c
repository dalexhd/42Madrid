/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:34:22 by aborboll          #+#    #+#             */
/*   Updated: 2020/03/10 15:53:48 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		apply_negative(t_info *info)
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
