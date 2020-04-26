/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 14:37:48 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_flags_aff_prepa(char *arg, t_parsing *parsing, char c)
{
	c = ' ';
	if (parsing->zero == 1)
		c = '0';
	if (*arg == 'c' && parsing->prec >= 0)
		parsing->prec = -1;
	if (*parsing->aff == '0' && parsing->prec == 0)
	{
		parsing->aff = NULL;
		parsing->neg = 0;
		parsing->space_flags += 1;
	}
	if (*arg == 'c' && !ft_strlen(parsing->aff))
	{
		parsing->cnull = 0;
		if (parsing->neg == 1)
		{
			ft_putchar_fd(parsing->cnull, 1);
			parsing->cnull = 1;
		}
		if (parsing->space_flags >= 1)
			parsing->space_flags -= 1;
	}
	//printf(">>>>out flags_aff_prepa, count is [%d]\n", parsing->arg_count);
}

void	ft_flags_count(char *arg, t_parsing *parsing, int flags_size)
{
	if (parsing->zero == 0)
	{
		parsing->space_flags = (parsing->prec <= ft_strlen(parsing->aff)) ?
			(parsing->width - ft_strlen(parsing->aff)) :
			(parsing->width - parsing->prec);
		parsing->zero_flags = parsing->prec - ft_strlen(parsing->aff);
		if (*arg == 'p' && ft_strlen(parsing->aff) == 2)
			parsing->space_flags += 1;
		if (*arg == 'p' && ft_strlen(parsing->aff) == 1 && parsing->prec == 0)
			parsing->arg_count -= 1;
	}
	else if (parsing->zero == 1)
	{
		parsing->space_flags = (parsing->prec <= 0) ?
			(parsing->width - ft_strlen(parsing->aff)) :
			(parsing->width - (parsing->prec));
		parsing->zero_flags = parsing->prec - ft_strlen(parsing->aff);
		if (parsing->prec < 0)
			parsing->zero_flags = parsing->space_flags;
	}
	if (*arg == 'p')
		parsing->space_flags -= 2;
	parsing->arg_count += (ft_get_count(arg, parsing, flags_size) - 1);
}

int		ft_get_flags(char *arg, t_parsing *parsing)
{
	int	i;

	i = 0;
	if (*arg)
	{
		while (arg[i] == '-' || arg[i] == '0')
		{
			if (arg[i] == '-')
			{
				parsing->neg = 1;
				parsing->zero = 0;
			}
			if (arg[i] == '0')
				if (parsing->neg == 0)
					parsing->zero = 1;
			i++;
		}
	}
	return (i);
}

int		ft_width(char *arg, va_list *av, t_parsing *parsing)
{
	int i;

	i = 0;
	if (*arg && ft_is_digit(arg[i]))
	{
		while (ft_is_digit(arg[i]))
			i++;
		parsing->width = ft_atoi(arg);
	}
	else if (*arg && arg[i] == '*')
	{
		parsing->width = va_arg(*av, unsigned int);
		if (parsing->width < 0)
		{
			parsing->neg = 1;
			parsing->zero = 0;
			parsing->width *= -1;
		}
		i++;
	}
	return (i);
}

int		ft_precision(char *arg, va_list *av, t_parsing *parsing)
{
	int i;

	i = 0;
	if (*arg && arg[i] == '.')
	{
		arg++;
		parsing->prec = 0;
		if (*arg && ft_is_digit(arg[i]))
		{
			parsing->prec = ft_atoi(arg);
			while (ft_is_digit(arg[i]))
				i++;
		}
		else if (*arg && arg[i] == '*')
		{
			parsing->prec = va_arg(*av, unsigned int);
			if (parsing->prec < 0)
				parsing->prec = -1;
			i++;
		}
		i++;
	}
	return (i);
}
