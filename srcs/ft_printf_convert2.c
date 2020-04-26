/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_convert2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 12:12:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <stdio.h>

int			ft_atoi(const char *str)
{
	int	i;
	int	m;
	int	nb;

	i = 0;
	m = 1;
	nb = 0;
	while (str[i] != '\0' && (str[i] == ' ' || str[i] == '\t' || str[i] ==
				'\n' || str[i] == '\v' || str[i] == '\f'
				|| str[i] == '\r'))
		i++;
	if (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			m *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb * m);
}

char		*ft_putnbr_base_ulong2(unsigned long nbr, char *base, int size_base)
{
	int		i;
	int		nbr_final[1000];
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (nbr)
	{
		nbr_final[i] = nbr % size_base;
		nbr = nbr / size_base;
		i++;
	}
	if (!(tmp = (char *)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	while (--i >= 0)
		tmp[j++] = base[nbr_final[i]];
	tmp[j] = '\0';
	return (tmp);
}

char		*ft_putnbr_base_ulong(unsigned long nbr, char *base)
{
	int		i;
	int		size_base;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	size_base = ft_strlen(base);
	if (!nbr)
	{
		tmp = (char *)malloc(sizeof(char *) * 2);
		tmp[j] = '0';
		j--;
		return (tmp);
	}
	else
		tmp = ft_putnbr_base_ulong2(nbr, base, size_base);
	return (tmp);
}
