/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:49:43 by aborboll          #+#    #+#             */
/*   Updated: 2019/11/16 17:10:50 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*next;
	t_list	*new;

	new = *lst;
	if (new)
	{
		while (new)
		{
			next = new->next;
			del(new->content);
			free(new);
			new = next;
		}
		*lst = NULL;
	}
}
