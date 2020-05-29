/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <apreymon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 16:36:14 by apreymon          #+#    #+#             */
/*   Updated: 2019/12/10 21:59:07 by tharchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "get_next_line.h"

char			*ft_substr(char *s, unsigned int start, size_t len)
{
	char			*copy;
	unsigned int	i;
	size_t			ssize;
	i = 0;
	ssize = ft_strlen((char *)s);
	if (s == NULL)
		return (NULL);
	copy = try_malloc(sizeof(char) * (len + 1), _FL_);
	// if (!(copy = malloc(sizeof(char) * (len + 1))))
	// 	return (NULL);
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

char			*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while(src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (	dest);
}

char			*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	while (s1[i])
		i++;
	copy = try_malloc(sizeof(char) * (i + 1), _FL_);
	// if (!(copy = malloc(sizeof(char) * (i + 1))))
	// 	return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char			*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (unsigned char)c)
		return ((char *)&str[i]);
	return (0);
}
