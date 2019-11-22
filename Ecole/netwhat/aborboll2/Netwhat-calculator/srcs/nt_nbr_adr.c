/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_nbr_adr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:39:26 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 14:09:55 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_calculator.h"
#include "netwhat_calculator_utils.c"

int		ft_iterative_power(int nb, int power)
{
	int total;
	int x;

	total = nb;
	x = 1;
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	if (power == 1)
		return (nb);
	while (x < power)
	{
		total = total * nb;
		x++;
	}
	return (total);
}

int     nt_nbr_adr(int c)
{
    int	nbr_avlb_adr;

	nbr_avlb_adr = ft_iterative_power(2, 32 - c) - 2;
    return (nbr_avlb_adr);
}

int main(int argc, char **argv)
{
	int	res;
	int	decimal;

	if (argc == 2)
	{
		decimal = atoi(argv[1]);
		res = nt_nbr_adr(decimal);
		if (decimal <= 0 || decimal >= 32)
			printf("Please type the correct number");
		if (decimal > 0 && decimal < 32)
			printf("%d", res);
		return (0);
	}
	return (0);
}