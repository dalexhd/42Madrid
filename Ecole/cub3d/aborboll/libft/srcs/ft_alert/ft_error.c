/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:15:10 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/13 13:34:42 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void		ft_error(char *s, t_bool force, ...)
{
	va_list args;

	va_start(args, force);
	ft_printf(C_RED"Error\n\t❌ ");
	ft_vprintf(s, &args);
	ft_printf(C_X"\n");
	va_end(args);
	if (force)
		exit(EXIT_FAILURE);
}
