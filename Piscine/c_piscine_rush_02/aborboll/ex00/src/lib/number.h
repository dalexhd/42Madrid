/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/21 14:13:06 by acarvaja          #+#    #+#             */
/*   Updated: 2019/09/21 23:20:54 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _NUMBER_H
# define _NUMBER_H

typedef struct	s_nbrtree
{
	char				*nbr;
	char				*nbrstr;
	struct s_nbrtree	*left;
	struct s_nbrtree	*right;
}				t_nbrtree;
#endif
