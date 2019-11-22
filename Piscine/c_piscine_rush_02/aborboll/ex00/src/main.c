/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 21:00:46 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:09:02 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/generic.h"

int		main(int argc, char **argv)
{
	char	*dict;
	int		j;
	int		k;
	char	*number;

	j = 0;
	k = 0;
	ft_checkerror(argc);
	if (argc < 3)
	{
		number = argv[1];
		dict = load_dictionary("es");
	}
	if (argc == 3)
	{
		number = argv[2];
		dict = load_dictionary(argv[1]);
	}
	if (!ft_isnbr(number))
		ft_error("El número que has introducido no es válido.\n");
	convert_to_word(number, dict, j, k);
	ft_putstr("\n");
	return (0);
}
