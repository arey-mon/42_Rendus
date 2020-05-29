/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:45:02 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/20 16:38:16 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t count)
{
	size_t			i;
	unsigned char	*destdeux;
	unsigned char	*srcdeux;

	i = 0;
	if (!dest && !src)
		return (NULL);
	destdeux = (unsigned char *)dest;
	srcdeux = (unsigned char *)src;
	while (i < count)
	{
		destdeux[i] = srcdeux[i];
		i++;
	}
	return (destdeux);
}
