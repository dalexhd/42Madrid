/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 11:05:20 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:46:27 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../lib/generic.h"

void		dto(int j, int *i, char **argv, t_nbrtree *my_tree)
{
	int			rightmove;
	int			leftmove;
	t_nbrtree	*ptr;

	ptr = my_tree;
	rightmove = argv[j][*i] - '0';
	leftmove = *i % 2;
	if (leftmove != 0 && argv[j][*i] != '0')
	{
		while (leftmove-- > 0)
		{
			ptr = ptr->left;
			if ((argv[j][*i] - '0') == 1)
				ptr = do_decens(ptr, i, j, argv);
			else
				ptr = do_decens2(argv, i, j, my_tree);
		}
	}
	else if ((*i == 0 || *i == 2) && argv[j][*i] > '0')
		do_one_digit(my_tree, argv, j, *i);
}

int			calc_k(int k, char **argv, int j)
{
	while (k < 3)
	{
		if (argv[j][k] == '0')
			k++;
		else
			break ;
	}
	return (k);
}

int			reorganizate(int k, char **argv, int j, t_nbrtree *ptr)
{
	k = calc_k(k, argv, j);
	if (k < 3)
	{
		ptr = move_left_on_tree(ptr, j + 2);
		ft_putstr_with_space((*ptr).nbrstr);
	}
	return (--j);
}

void		print_number(char *arg, t_nbrtree *my_tree, int i, int k)
{
	int			digits;
	int			j;
	char		**argv;
	t_nbrtree	*ptr;

	ptr = my_tree;
	digits = ft_strlen(arg);
	j = 0;
	argv = initargv(arg, digits, &j, k);
	j -= 1;
	while (digits > 0)
	{
		k = 0;
		i = calc_i(digits);
		while (i < 3)
		{
			i % 3 == 0 ? dt(j, i, argv, my_tree) : dto(j, &i, argv, my_tree);
			ptr = my_tree;
			i++;
		}
		if (j > 0)
			j = reorganizate(k, argv, j, ptr);
		digits = calc_next_digits(digits);
		ptr = my_tree;
	}
}
