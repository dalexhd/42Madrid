/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:09:54 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/11 17:54:11 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (str[0] != '\0')
	{
		if ((str[0] < 97 || str[0] > 122) && (str[0] < 65 || str[0] > 90))
			return (0);
		str++;
	}
	return (1);
}
