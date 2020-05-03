/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_write.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 15:26:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_printf.h"

char	*ft_aff_c(int d)
{
	char	*str;
	int		i;
	char	c;

	c = (char)d;
	i = 0;
	if (!c)
	{
		if (!(str = malloc(1 * sizeof(char))))
			return (NULL);
	}
	else
	{
		if (!(str = malloc((2) * sizeof(char))))
			return (NULL);
	}
	if (c)
		str[i++] = c;
	str[i] = '\0';
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*copy;

	i = 0;
	if (!s1)
	{
		copy = ft_strdup("(null)");
		return (copy);
	}
	while (s1[i])
		i++;
	if (!(copy = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	ft_putchar_fd(char c, int fd)
{
	write(1, &c, fd);
}

int		ft_putstr_fd(const char *format, int fd)
{
	size_t i;

	i = 0;
	(void)fd;
	while (format[i])
	{
		ft_putchar_fd(format[i], 1);
		i++;
	}
	return (i);
}
