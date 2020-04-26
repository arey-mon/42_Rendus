/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 12:10:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_nbrlen(int f)
{
	int	i;
	int	res;

	res = f;
	i = 0;
	if (f == 0)
		return (1);
	while (f != 0)
	{
		f = f / 10;
		i++;
	}
	if (res < 0)
		return (i + 1);
	return (i);
}

char		*ft_itoa(int n)
{
	char	*tmp;
	long	nb;
	int		i;
	int		d;

	i = 0;
	d = 1;
	nb = n;
	if (!(tmp = malloc(sizeof(char) * ft_nbrlen((int)nb) + 1)))
		return (NULL);
	if (nb < 0)
	{
		tmp[i] = '-';
		nb *= -1;
		i++;
	}
	while (nb / d >= 10)
		d *= 10;
	while (d > 0)
	{
		tmp[i++] = (nb / d) % 10 + '0';
		d /= 10;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = '\0';
	return (s1);
}

static char	*ft_strcat(char *s1, char *s2)
{
	int	i;
	int	j;

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

char		*ft_strjoin(char const *s1, char const *s2)
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
