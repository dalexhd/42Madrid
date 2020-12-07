/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendswith.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 17:49:32 by aborboll          #+#    #+#             */
/*   Updated: 2020/10/10 17:54:36 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_bool		ft_strendswith(const char *haystack, const char *needle)
{
	return (!ft_strcmp(ft_strrchr(haystack, '\0') -
		ft_strlen(needle), needle));
}
