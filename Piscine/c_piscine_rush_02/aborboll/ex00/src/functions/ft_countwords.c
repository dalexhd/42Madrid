/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 16:25:44 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 16:27:39 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		count_words(char *str)
{
	int		count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		if (*str && *str != ' ' && *str != '\n' && *str != '\t')
		{
			count++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	return (count);
}
