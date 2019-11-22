/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:09:06 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:24:51 by acarvaja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/generic.h"
#include <stdio.h>

void	try_zero(char *arg, t_nbrtree *my_tree)
{
	if (*arg == '0')
		ft_putstr((*my_tree).nbrstr);
}

void	convert_to_word(char *arg, char *dicct, int j, int k)
{
	char		**table;
	int			i;
	char		*nbr;
	char		*nbrstr;
	t_nbrtree	*my_tree;

	i = 0;
	table = ft_split(dicct, "\n", i, j);
	table = separate_order(table);
	while (table[i] != '\0')
		i++;
	my_tree = malloc(sizeof(t_nbrtree) * i);
	i = -1;
	while (table[++i + 2] != '\0')
	{
		nbr = reserve_memorynbr(table[i]);
		if (*table[i] != ' ')
			my_tree[i].nbr = set_nbr(nbr, my_tree[i]);
		nbrstr = reserve_memorynbrstr(table[i], nbrstr);
		if (*table[i] != ' ')
			my_tree[i].nbrstr = set_nbrstr(nbrstr, my_tree[i]);
	}
	my_tree = structure_tree(my_tree, i);
	try_zero(arg, my_tree);
	print_number(arg, my_tree, j, k);
}
