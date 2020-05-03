/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 22:52:46 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_pointers_prepa(char *arg, t_parsing *parsing)
{
	(void)*arg;
	if (parsing->aff == NULL)
	{
		parsing->aff = ft_strdup("0x");
		parsing->arg_count += 1;
	}
	else if (parsing->prec < ft_strlen(parsing->aff))
		parsing->aff = ft_strjoin(ft_strdup("0x"), parsing->aff);
}

void	ft_pointers_neg(t_parsing *parsing)
{
	char c;

	c = ' ';
	if (parsing->zero == 1)
		c = '0';
	ft_putstr_fd(parsing->aff, 1);
	while (parsing->space_flags-- > 0)
	{
		write(1, &c, 1);
		parsing->arg_count++;
	}
	parsing->arg_count += ft_strlen(parsing->aff);
	parsing->aff = NULL;
}

void	ft_pointers_deal(char *arg, t_parsing *parsing)
{
	(void)*arg;
	ft_pointers_prepa(arg, parsing);
	if (parsing->neg == 1)
		ft_pointers_neg(parsing);
	else if (parsing->neg == 0)
	{
		while (parsing->space_flags-- > 0)
		{
			ft_putchar_fd(' ', 1);
			parsing->arg_count++;
		}
		if (parsing->prec > ft_strlen(parsing->aff))
		{
			ft_putstr_fd("0x", 1);
			while (parsing->zero_flags-- > 0)
			{
				ft_putchar_fd('0', 1);
				parsing->arg_count++;
			}
			ft_putstr_fd(parsing->aff, 1);
			parsing->arg_count += ft_strlen(parsing->aff) + 2;
			parsing->aff = NULL;
		}
	}
}
