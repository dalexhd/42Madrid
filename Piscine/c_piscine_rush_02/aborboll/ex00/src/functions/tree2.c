/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:36:38 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/22 21:59:03 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

t_nbrtree	*move_right_on_tree(t_nbrtree *binary, int n)
{
	while (n-- > 0)
		binary = binary->right;
	return (binary);
}

t_nbrtree	*move_left_on_tree(t_nbrtree *binary, int n)
{
	while (n-- > 0)
		binary = binary->left;
	return (binary);
}

void		ft_swap(char *a, char *b)
{
	char swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

void		ft_rev_int_tab(char *tab, int size)
{
	int i;
	int j;

	i = 0;
	j = size - 1;
	while (i != size / 2)
	{
		ft_swap(&tab[i], &tab[j]);
		i++;
		j--;
	}
}

void		revert_argv(char **argv, char *arg)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (ft_strlen(arg) > i)
	{
		ft_rev_int_tab(argv[k], ft_strlen(argv[k]));
		k++;
		i += 3;
	}
}
