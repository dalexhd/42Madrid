/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 10:48:14 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/16 15:00:08 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int c;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		c = 0;
		while (to_find[c] == str[i + c])
		{
			if (to_find[c + 1] == '\0')
			{
				return (str + i);
			}
			c++;
		}
		i++;
	}
	return (0);
}
