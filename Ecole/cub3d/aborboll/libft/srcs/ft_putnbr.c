/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 21:12:01 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_putnbr(int n)
{
	t_uint	nbr;

	if (n != '\0')
	{
		if (n < 0)
		{
			ft_putchar_fd('-', 1);
			nbr = (t_uint)(n * -1);
		}
		else
			nbr = (t_uint)(n);
		if (nbr >= 10)
			ft_putnbr_fd(nbr / 10, 1);
		ft_putchar_fd((nbr % 10) + '0', 1);
	}
}
