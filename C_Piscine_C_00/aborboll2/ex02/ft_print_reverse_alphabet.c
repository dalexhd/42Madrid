/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 12:28:53 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/07 20:08:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	int y;

	y = 122;
	while (y >= 97)
	{
		write(1, &y, 1);
		y--;
	}
}


int main(void)
{
	ft_print_reverse_alphabet();
	return (0);
}