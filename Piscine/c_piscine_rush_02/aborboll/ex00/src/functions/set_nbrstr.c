/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_nbrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 12:46:45 by aborboll          #+#    #+#             */
/*   Updated: 2019/09/22 12:47:56 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/number.h"

char	*set_nbrstr(char *nbrstr, t_nbrtree binary)
{
	binary.nbrstr = nbrstr;
	return (binary.nbrstr);
}
