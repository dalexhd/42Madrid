/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 00:04:48 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/26 13:49:49 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_range(int min, int max)
{
	int	*numbers;
	int i;
	int z;
	int s;

	s = max - min;
	if (!(numbers = (int*)malloc(4 * s < 0 ? (max - min) * -1 : max - min)))
		return (0);
	i = 0;
	z = min;
	while (z < max)
		numbers[i++] = z++;
	return (numbers);
}
