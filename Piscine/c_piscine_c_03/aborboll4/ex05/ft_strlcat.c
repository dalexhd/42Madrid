/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:48:31 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/23 22:46:06 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	e;

	i = 0;
	while (dest[i] != '\0')
		++i;
	e = 0;
	while (src[e] != '\0')
		++e;
	if (size <= i)
		e += size;
	else
		e += i;
	j = 0;
	while (src[j] != '\0' && i + 1 < size)
		dest[++i] = src[++j];
	dest[i] = '\0';
	return (e);
}
