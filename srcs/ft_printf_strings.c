/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_strings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 22:48:00 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_strings(char *arg, t_parsing *parsing, char *tmp)
{
	char c;

	c = ' ';
	tmp = ft_strdup(parsing->aff);
	if (parsing->zero == 1)
		c = '0';
	if (parsing->prec == 0 && ft_strlen(parsing->aff) <= parsing->width
			&& parsing->neg == 1)
	{
		ft_putstr_fd(tmp, 1);
		parsing->arg_count += ft_strlen(tmp);
	}
	if (parsing->prec >= 0)
		ft_string_precision(arg, parsing, c, tmp);
}

void	ft_string_precision2(t_parsing *parsing, char c, char *tmp)
{
	int		i;

	i = 0;
	while (parsing->width-- - parsing->prec > 0 && parsing->neg != 1)
	{
		write(1, &c, 1);
		parsing->arg_count++;
	}
	while (parsing->prec-- > 0)
	{
		ft_putchar_fd(tmp[i++], 1);
		parsing->arg_count++;
	}
	parsing->width -= i;
	while (parsing->width-- - parsing->prec > 0 && parsing->neg == 1)
	{
		write(1, &c, 1);
		parsing->arg_count++;
	}
	while (parsing->prec-- - ft_strlen(tmp) > 0)
	{
		ft_putchar_fd(' ', 1);
		parsing->arg_count++;
	}
	parsing->aff = NULL;
}

void	ft_string_precision(char *arg, t_parsing *parsing, char c, char *tmp)
{
	int		i;

	i = 0;
	ft_string_exceptions(arg, parsing, c, tmp);
	if (ft_strlen(tmp) >= parsing->prec)
		ft_string_precision2(parsing, c, tmp);
	else if (ft_strlen(tmp) < parsing->prec)
	{
		while (parsing->neg != 1 && parsing->width-- - ft_strlen(tmp) > 0)
		{
			write(1, &c, 1);
			parsing->arg_count++;
		}
		if (parsing->neg == 1)
		{
			ft_putstr_fd(tmp, 1);
			while (parsing->width-- - ft_strlen(tmp) > 0)
			{
				write(1, &c, 1);
				parsing->arg_count++;
			}
			parsing->arg_count += ft_strlen(parsing->aff);
			parsing->aff = NULL;
		}
	}
}

void	ft_string_exceptions(char *arg, t_parsing *parsing, char c, char *tmp)
{
	tmp = ft_strdup(parsing->aff);
	if (parsing->prec == 0 && *arg == 's')
		while (parsing->width--)
		{
			write(1, &c, 1);
			parsing->arg_count++;
		}
	if (parsing->prec == 0 && *arg == 'c')
	{
		if (parsing->neg != 1)
		{
			while (parsing->space_flags-- > 0)
			{
				write(1, &c, 1);
				parsing->arg_count++;
			}
			ft_putchar_fd(*tmp, 1);
			parsing->arg_count += 1;
		}
		else if (parsing->neg == 1)
		{
			ft_putchar_fd(*tmp, 1);
			parsing->arg_count += 1;
			while (parsing->space_flags-- > 0)
			{
				write(1, &c, 1);
				parsing->arg_count++;
			}
		}
		parsing->aff = NULL;
	}
}
