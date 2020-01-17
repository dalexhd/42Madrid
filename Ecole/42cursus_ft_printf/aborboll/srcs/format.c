/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 11:17:42 by aborboll          #+#    #+#             */
/*   Updated: 2019/12/06 15:23:45 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	isValid(char *str)
{
	(void) str;
	return (true);
}

int		parse_format(const char *str, va_list list)
{
	size_t	i;
	size_t	start;
	t_bool	valid;
	char	*check;

	(void) list;
	i = 0;
	valid = false;
	while (str[i])
	{
		start =0;
		valid = 0;
		if (str[i] != '%')
		{
			check = ft_substr(str, i, ft_strlen(str));
			printf("str[%zu] = %s", i, check);
			free(check);
		}
		i++;
	}
	return (0);
}
