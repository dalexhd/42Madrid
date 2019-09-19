/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 14:12:21 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/12 15:37:38 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int		i;
	char	bef;
	char	curr;

	i = 0;
	while (str[i] != '\0')
	{
		bef = str[i - 1];
		curr = str[i];
		if (i == 0 || bef == ' ' || bef == '-' || bef == '+')
		{
			if (curr >= 97 && curr <= 122)
				str[i] -= 32;
		}
		else if (curr >= 65 && curr <= 90)
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}
