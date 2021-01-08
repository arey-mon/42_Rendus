/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:43:51 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/18 17:22:37 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*current;
	t_list	*last;

	current = lst;
	if (!lst)
		return (NULL);
	while (current != NULL)
	{
		if (current->next == NULL)
			last = current;
		current = current->next;
	}
	return (last);
}
