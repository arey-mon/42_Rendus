/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:51:58 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/21 16:37:21 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
 Testing ft_lstmap
 [!] Error - Unapplied mapping function
 [!] Expected mapped first link's content : ABC
 [!] Got : }T
 [!] Error - Unapplied mapping function
 [!] Expected mapped second link's content : DEF
 [!] Got : }T
 [*] ft_lstmap : [ko]
 */

t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *))
{
	t_list	*current;
	t_list	*begin_list;

	begin_list = ft_lstnew(f(lst));
	current = begin_list;
	if (!lst || !f)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		current->next = ft_lstnew(f(lst));
		if (!(current->next))
		{
			del(current->next);
			return (0);
		}
		current = current->next;
	}
	return (begin_list);
}
