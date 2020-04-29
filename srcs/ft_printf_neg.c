/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_neg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/29 17:57:53 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_neg_value_w2(t_parsing *parsing)
{
	if (parsing->zero == 1 && parsing->prec > ft_strlen(parsing->aff))
		parsing->zero_flags += 1;
	while ((parsing->zero_flags-- - 1) > 0)
	{
		ft_putchar_fd('0', 1);
		parsing->arg_count++;
	}
}

void	ft_neg_value_w(t_parsing *parsing)
{
	parsing->space_flags = parsing->prec >= ft_strlen(parsing->aff) ?
		parsing->width - parsing->prec : (parsing->width -
				ft_strlen(parsing->aff) + 1);
	if (parsing->prec < ft_strlen(parsing->aff) && parsing->prec != -1)
		*parsing->aff = '-';
	else if (parsing->prec == -1 && parsing->zero == 1)
		*parsing->aff = '0';
	else if (parsing->prec >= ft_strlen(parsing->aff))
		*parsing->aff = '0';
	parsing->space_flags -= 1;
	if ((parsing->zero == 1 && parsing->prec != -1) || (parsing->zero != 1 &&
				parsing->width > ft_strlen(parsing->aff)))
		while (parsing->space_flags-- > 0)
		{
			ft_putchar_fd(' ', 1);
			parsing->arg_count++;
		}
	if (*parsing->aff == '0')
	{
		ft_putchar_fd('-', 1);
		parsing->arg_count++;
	}
	ft_neg_value_w2(parsing);
}

void	ft_neg_value_p(char *arg, t_parsing *parsing)
{
	if (*arg != 'u')
	{
		ft_putchar_fd('-', 1);
		parsing->arg_count++;
	}
	while (parsing->zero_flags-- > 0)
	{
		ft_putchar_fd('0', 1);
		parsing->arg_count++;
	}
	if (parsing->width > ft_strlen(parsing->aff) && parsing->prec >
			ft_strlen(parsing->aff))
		parsing->space_flags = (parsing->width - parsing->prec - 1);
	while (parsing->space_flags-- > 0)
	{
		ft_putchar_fd(' ', 1);
		parsing->arg_count++;
	}
	if (parsing->width != 0)
		parsing->zero_flags += 1;
	while (parsing->zero_flags-- > 0)
	{
		ft_putchar_fd('0', 1);
		parsing->arg_count++;
	}
}

void	ft_neg_value(char *arg, t_parsing *parsing)
{
	int size;

	(void)*arg;
	size = parsing->prec >= parsing->width ? parsing->prec : parsing->width;
	ft_neg_prepare(arg, parsing);
	if (parsing->prec < size && parsing->prec == ft_strlen(parsing->aff))
		parsing->space_flags += 1;
	if (ft_strlen(parsing->aff) >= size)
		parsing->space_flags = 0;
	if (parsing->neg == 1)
		ft_double_neg(arg, parsing);
	else
	{
		if (parsing->prec >= ft_strlen(parsing->aff) || parsing->prec == -1)
			parsing->space_flags -= 1;
		if (parsing->width > ft_strlen(parsing->aff) &&
				parsing->width > parsing->prec)
			ft_neg_value_w(parsing);
		else if (parsing->prec >= ft_strlen(parsing->aff)
				&& parsing->width <= parsing->prec)
			ft_neg_value_p(arg, parsing);
	}
}

void	ft_double_neg(char *arg, t_parsing *parsing)
{
	if (parsing->width <= ft_strlen(parsing->aff))
		parsing->space_flags = 0;
	if (parsing->prec >= ft_strlen(parsing->aff) && parsing->width >=
			ft_strlen(parsing->aff))
		parsing->space_flags -= 1;
	if ((ft_strlen(parsing->aff) <= parsing->prec))
	{
		if (*arg != 'u' && parsing->arg_pos != 1)
			ft_putchar_fd('-', 1);
		if (parsing->width != 0)
			parsing->arg_count += 1;
	}
	while (parsing->zero_flags-- > 0)
	{
		ft_putchar_fd('0', 1);
		parsing->arg_count++;
	}
	ft_putstr_fd(parsing->aff, 1);
	while (parsing->space_flags-- > 0)
	{
		ft_putchar_fd(' ', 1);
		parsing->arg_count++;
	}
	parsing->arg_count += ft_strlen(parsing->aff);
	parsing->aff = NULL;
}
