/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:36:40 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/22 22:48:43 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../lib/generic.h"

char		**initargv(char *arg, int digits, int *j, int k)
{
	int		i;
	char	**argv;

	argv = malloc(sizeof(char *) * 13);
	i = 0;
	k = 0;
	while (ft_strlen(arg) > i)
	{
		argv[k++] = malloc(sizeof(char) * 3);
		i += 3;
	}
	i = digits - 1;
	while (i >= 0)
	{
		k = 0;
		while (k < 3)
		{
			argv[*j][k++] = arg[i--];
			while (arg[i] == '\0' && k < 3)
				argv[*j][k++] = '0';
		}
		*j += 1;
	}
	revert_argv(argv, arg);
	return (argv);
}

int			calc_i(int digits)
{
	int i;

	i = digits % 3;
	if (i == 1)
		i = 2;
	else if (i == 2)
		i = 1;
	return (i);
}

int			calc_next_digits(int digits)
{
	if (digits % 3 == 0)
		digits -= 3;
	else
		digits -= (digits % 3);
	return (digits);
}

t_nbrtree	*structure_tree(t_nbrtree *my_tree, int i)
{
	int j;
	int flag;

	flag = 0;
	j = 0;
	while (j < i - 1)
	{
		if (ft_strlen(my_tree[j].nbr) == ft_strlen(my_tree[j + 1].nbr))
			my_tree[j].right = &my_tree[j + 1];
		else
		{
			my_tree[flag].left = &my_tree[j + 1];
			flag = j + 1;
		}
		j++;
	}
	return (my_tree);
}

void		dt(int j, int i, char **argv, t_nbrtree *my_tree)
{
	int			rightmove;
	int			leftmove;
	t_nbrtree	*ptr;

	ptr = my_tree;
	if (argv[j][i] > '0')
	{
		rightmove = argv[j][i] - '0';
		leftmove = 2;
		while (rightmove-- > 0)
			ptr = ptr->right;
		ft_putstr_with_space((*ptr).nbrstr);
		ptr = my_tree;
		while (leftmove-- > 0)
			ptr = ptr->left;
		ft_putstr_with_space((*ptr).nbrstr);
	}
}
