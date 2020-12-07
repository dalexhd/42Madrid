/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aborboll <aborboll@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 18:40:01 by aborboll          #+#    #+#             */
/*   Updated: 2020/08/28 17:08:59 by aborboll         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list		*new;
	t_list		*first;

	(void)(*del);
	if (f == NULL || lst == NULL)
		return (NULL);
	new = ft_lstnew(f(lst->content));
	if (new == NULL)
		return (NULL);
	first = new;
	while (lst->next != NULL)
	{
		lst = lst->next;
		new->next = ft_lstnew(f(lst->content));
		if (new->next == NULL)
			return (NULL);
		new = new->next;
	}
	return (first);
}
