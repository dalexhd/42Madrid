/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nt_tobinary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lacollar <lacollar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/27 08:31:20 by lacollar          #+#    #+#             */
/*   Updated: 2019/11/20 14:10:00 by lacollar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_calculator.h"
#include "netwhat_calculator_utils.c"

void    nt_tobinary(int nbr, char *base)
{
    int     remainder[10];
    int     i;
    int     size;

    if (nbr < 0)
		return ;    
    size = 0;
    while (base[size])
        size++;
    i = 0;
    while (nbr != 0)
    {
        remainder[i] = nbr % size;
        nbr /= size;
        i++;
    }
    while (i > 0)
        ft_putchar(base[remainder[--i]]);
}

int 	main(int argc, char **argv)
{
	int	    decimal;
    char    *base;

	if (argc == 2)
	{
		decimal = atoi(argv[1]);
        base = "01";
		if (decimal <= 0 || decimal >= 255)
			printf("Please type a correct number");
		if (decimal > 0 && decimal < 255)
			nt_tobinary(decimal, base);
		return (0);
	}
    else
        printf("Error");
	return (0);
}
