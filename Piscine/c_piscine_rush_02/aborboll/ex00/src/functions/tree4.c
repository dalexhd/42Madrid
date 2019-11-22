/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:36:41 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/22 22:47:25 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

void		do_one_digit(t_nbrtree *my_tree, char **argv, int j, int i)
{
	int			rightmove;
	t_nbrtree	*ptr;

	ptr = my_tree;
	rightmove = argv[j][i] - '0';
	while (rightmove-- > 0)
		ptr = move_right_on_tree(ptr, 1);
	if (argv[j][i] > '0')
		ft_putstr_with_space((*ptr).nbrstr);
}

t_nbrtree	*do_decens(t_nbrtree *ptr, int *i, int j, char **argv)
{
	*i += 1;
	while (argv[j][*i] > '0')
	{
		ptr = ptr->right;
		argv[j][*i] -= 1;
	}
	ft_putstr_with_space((*ptr).nbrstr);
	return (ptr);
}

t_nbrtree	*do_decens2(char **argv, int *i, int j, t_nbrtree *my_tree)
{
	t_nbrtree	*ptr;

	ptr = my_tree;
	ptr = ptr->left;
	ptr = move_right_on_tree(ptr, 10 + (argv[j][*i] - '0') - 2);
	ft_putstr_with_space((*ptr).nbrstr);
	ptr = my_tree;
	*i += 1;
	ptr = move_right_on_tree(ptr, argv[j][*i] - '0');
	if (argv[j][*i] > '0')
		ft_putstr_with_space((*ptr).nbrstr);
	return (ptr);
}
