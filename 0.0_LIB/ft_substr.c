/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:29:39 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/21 16:43:03 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>

static int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char			*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*copy;
	size_t			i;
	size_t			ssize;

	i = 0;
	ssize = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	if (!(copy = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start <= ssize)
	{
		while (len--)
		{
			copy[i] = s[start];
			i++;
			start++;
		}
	}
	copy[i] = '\0';
	return (copy);
}
