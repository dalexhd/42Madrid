/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 13:27:03 by cafernan          #+#    #+#             */
/*   Updated: 2019/09/15 21:30:20 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(char *argv[]);
void	ft_printstr(char *str);
#include <stdlib.h>

int main(int argc, char *argv[])
{
/* 	if(argc < 17 || argc > 17)
	{
		ft_printstr("Error: Has introducido menos o más de 16 argumentos!\n");
		return (0);
	} */
	rush(argv);
	system("open ./music.mp3");
	return (0);
}
