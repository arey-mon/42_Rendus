/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_checks.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/23 22:14:16 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int		ft_is_digit(int d)
{
	if (d >= '0' && d <= '9')
		return (1);
	return (0);
}

int		ft_is_printf_format(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == 'c' || format[i] == 'd' || format[i] == 's' ||
			format[i] == 'x' || format[i] == 'X' || format[i] == 'p'
			|| format[i] == 'i' || format[i] == 'u' || format[i] == '%')
		return (1);
	return (0);
}

int		ft_is_flag(const char *format)
{
	int	i;

	i = 0;
	if (format[i] == '0' || format[i] == '-' || format[i] == '.' ||
			format[i] == '*')
		return (1);
	return (0);
}
