/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 13:08:35 by apreymon          #+#    #+#             */
/*   Updated: 2019/11/18 17:35:38 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static char		*ft_strcpy(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char		*ft_strcat(char *s1, char *s2)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	while (s2[j])
	{
		s1[i] = s2[j];
		j++;
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

char			*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*res;

	res = NULL;
	i = 0;
	if (s1 && s2)
	{
		if (!(res = malloc(sizeof(char *) *
						(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1))))
			return (NULL);
		ft_strcpy(res, (char *)s1);
		ft_strcat(((char *)res), (char *)s2);
	}
	return (res);
}
