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

void	ft_pointers_deal(char *arg, t_parsing *parsing)
{
	(void)*arg;
	if (parsing->aff == NULL)
	{
		parsing->aff = ft_strdup("0x");
		parsing->arg_count += 1;
	}
	else if (parsing->prec < ft_strlen(parsing->aff))
		parsing->aff = ft_strjoin(ft_strdup("0x"), parsing->aff);
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
