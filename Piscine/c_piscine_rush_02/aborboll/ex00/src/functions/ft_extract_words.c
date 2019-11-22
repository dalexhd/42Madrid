/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 13:22:04 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 23:29:14 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../lib/generic.h"

char	*malloc_word(char *str)
{
	char	*word;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split_line(char *str)
{
	int		words;
	char	**tab;
	int		i;

	words = count_words(str);
	tab = (char **)malloc(sizeof(char*) * (words + 1));
	i = 0;
	while (*str)
	{
		while (*str && (*str == ' ' || *str == '\n' || *str == '\t'))
			str++;
		if (*str && *str != ' ' && *str != '\n' && *str != '\t')
		{
			tab[i] = malloc_word(str);
			i++;
			while (*str && *str != ' ' && *str != '\n' && *str != '\t')
				str++;
		}
	}
	tab[i] = NULL;
	return (tab);
}


char	*extract_words(char *src)
{
	char *text;
	char *number;

	number = ft_split_line(src)[0];
	text = (char *)malloc(sizeof(char) * ft_strlen(src));
	strcpy(text, number);
	strcat(text, " ");
	strcat(text, ft_split_line(src)[1]);
	return (text);
}
