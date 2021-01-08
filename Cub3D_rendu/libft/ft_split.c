/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:27:02 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/18 17:31:24 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char		*ft_strndup(const char *src, size_t len)
{
	char	*dup;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(dup = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (src[i] && i < len)
	{
		dup[j] = src[i];
		i++;
		j++;
	}
	dup[j] = 0;
	return (dup);
}

size_t			current_size(char const **s, char c)
{
	size_t size;

	size = 0;
	while (**s && **s == c)
		(*s)++;
	while (s[0][size] && s[0][size] != c)
		size++;
	return (size);
}

int				size_to_cut(char const *s, char c)
{
	size_t	nb;
	int		tf;

	nb = 0;
	while (*s)
	{
		tf = 0;
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			tf = 1;
			s++;
		}
		if (tf == 1)
			nb++;
	}
	return (nb);
}

char			**free_split(size_t i, char **new)
{
	size_t	j;

	j = 0;
	while (j < i)
	{
		free(new[j]);
		j++;
	}
	free(new);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	size;
	size_t	size_cut;
	size_t	i;

	if (!s)
		return (NULL);
	size = size_to_cut(s, c);
	if (!(res = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		size_cut = current_size(&s, c);
		if (!(res[i] = ft_strndup(s, size_cut)))
			free_split(i, res);
		s += size_cut;
		i++;
	}
	res[size] = NULL;
	return (res);
}
