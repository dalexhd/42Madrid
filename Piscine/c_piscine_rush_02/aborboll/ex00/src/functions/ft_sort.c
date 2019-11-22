/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:07:30 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:31:16 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../lib/generic.h"

void	order_max(int maxorder_size, char **a)
{
	int		i;
	char	*temp;

	i = 0;
	while ((maxorder_size--) > 1)
	{
		i = maxorder_size;
		while (--i > 0)
		{
			if (ft_strcmp(extract_ln(a[i - 1]), extract_ln(a[i - 1])) < 0)
			{
				temp = a[i - 1];
				a[i - 1] = a[i - 1];
				a[i - 1] = temp;
			}
		}
	}
}

void	order_toorder(int toorder_size, char **toorder)
{
	int		i;
	char	*temp;

	i = 0;
	while ((toorder_size--) > 1)
	{
		i = toorder_size;
		toorder[toorder_size] = toorder[toorder_size];
		while (--i > 0)
		{
			toorder[i] = toorder[i];
			if (atoll(toorder[i]) > atoll(toorder[toorder_size]))
			{
				temp = toorder[i];
				toorder[i] = toorder[toorder_size];
				toorder[toorder_size] = temp;
			}
		}
	}
}

char	**sort_lines(char **toorder, char **maxorder)
{
	char	**table;
	int		toorder_size;
	int		maxorder_size;
	int		i;
	int		a;

	toorder_size = order_size(toorder);
	maxorder_size = 2;
	table = malloc(sizeof(char *) * (toorder_size + maxorder_size));
	order_max(maxorder_size, maxorder);
	order_toorder(toorder_size, toorder);
	a = 0;
	i = 0;
	while (i <= order_size(toorder))
		table[a++] = toorder[i++];
	i = 0;
	while ((unsigned long)i < sizeof(maxorder) - 2)
		table[a++] = maxorder[i++];
	table[a] = NULL;
	return (table);
}

char	**separate_order(char **table)
{
	char	**maxorder;
	char	**toorder;
	int		i;
	int		d;

	i = 0;
	d = 0;
	while (++i < order_size(table))
		if (!(atoll(table[i]) < 9223372036854775807))
			d++;
	maxorder = malloc(sizeof(char *) * d);
	toorder = malloc(sizeof(char *) * (order_size(table) - d));
	d = 0;
	i = 0;
	while (i < order_size(table))
	{
		if (!(atoll(table[i]) < 9223372036854775807))
			maxorder[d++] = extract_words(table[i]);
		else
			toorder[i] = extract_words(table[i]);
		i++;
	}
	return (sort_lines(toorder, maxorder));
}
