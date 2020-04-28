/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags_aff.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 13:04:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void	ft_flags_aff2(char *arg, t_parsing *parsing)
{
	int space;

	(void)*arg;
	space = parsing->prec > ft_strlen(parsing->aff) ? parsing->width -
	parsing->prec : parsing->width - ft_strlen(parsing->aff);
	while (space-- > 0)
	{
		ft_putchar_fd(' ', 1);
		parsing->arg_count++;
	}
	if (parsing->prec > parsing->width)
		while (parsing->zero_flags-- > 0)
		{
			ft_putchar_fd('0', 1);
			parsing->arg_count++;
		}
}

void	ft_flags_aff3(char *arg, t_parsing *parsing, char c, char *tmp)
{ //printf("\nflags_aff3, aff is [%s]\n", parsing->aff);
	if (parsing->prec > parsing->width || parsing->prec == -1)
	{
		if (*arg == '%')
		{
			if (parsing->zero == 1)
				c = '0';
			while (parsing->width-- - ft_strlen(tmp) > 0)
			{
				write(1, &c, 1);
				parsing->arg_count++;
			}
		}
		else
			while (parsing->zero_flags-- > 0)
			{
				ft_putchar_fd('0', 1);
				parsing->arg_count++;
			}
	}
	while (*arg != '%' && parsing->zero != 1 && parsing->space_flags-- > 0)
	{
		write(1, &c, 1);
		parsing->arg_count++;
	}
}

void	ft_flags_aff(char *arg, t_parsing *parsing, char c)
{
	char *tmp;
//printf("\n>>>into flags_aff, your aff is [%s]\n", parsing->aff);
	c = ' ';
	tmp = ft_strdup(parsing->aff);
	ft_flags_aff_prepa(arg, parsing, c);
	if (*arg == 's' && parsing->prec == 0)
		parsing->aff = "";
	if ((*arg == 's' || *arg == 'c') && parsing->prec >= 0)
		ft_strings(arg, parsing);
	else if ((*tmp == '-' || parsing->neg == 1))
		ft_neg_value(arg, parsing);
	else if (*arg == 'p' && parsing->neg != 1)
		ft_pointers_deal(arg, parsing);
	else
	{ //printf("else of flags_aff\n");
		if (parsing->zero == 1 && parsing->prec != -1 && parsing->aff != NULL)
			ft_flags_aff2(arg, parsing);
		else
			ft_flags_aff3(arg, parsing, c, tmp);
		if (parsing->prec <= parsing->width && parsing->prec != -1)
			while (parsing->zero_flags-- > 0)
			{
				ft_putchar_fd('0', 1);
				parsing->arg_count++;
			}
	}
	//printf(">>>>out of flags_aff, count is [%d]\n", parsing->arg_count);
}
