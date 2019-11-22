/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 21:19:12 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 22:19:22 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/generic.h"

void	ft_checkerror(int argc)
{
	if (argc > 3)
		ft_error("Demasiados argumentos...\n");
	if (argc < 2)
	{
		ft_error_no_exit("Necesitas intoducir 1 número\n");
		ft_info("Syntax: ./executable [?lang (en, gb)] [!number]\n");
	}
}
