/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_neg_prepare.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 15:44:15 by apreymon          #+#    #+#             */
/*   Updated: 2020/04/24 22:43:50 by apolliner        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

void	ft_neg_prepare2(char *arg, t_parsing *parsing)
{
	if (*arg == 'p')
		parsing->aff = ft_strjoin(ft_strdup("0x"), parsing->aff);
	else if (*arg == 'u')
	{
		if (parsing->prec > ft_strlen(parsing->aff))
		{
			parsing->space_flags += 1;
			parsing->arg_count -= 1;
		}
		else if (parsing->prec == ft_strlen(parsing->aff))
			parsing->arg_count -= 1;
		else if (parsing->prec < ft_strlen(parsing->aff) &&
				parsing->prec != -1 && parsing->zero == 1)
			parsing->space_flags -= 1;
	}
}

void	ft_neg_prepare3(t_parsing *parsing, int aff_count)
{
	aff_count = *parsing->aff == '-' ?
		ft_strlen(parsing->aff) - 1 : ft_strlen(parsing->aff);
	if (*parsing->aff == '-')
	{
		*parsing->aff = parsing->prec > aff_count ? '0' : *parsing->aff;
		if (parsing->prec > aff_count && parsing->width >
			parsing->prec && parsing->neg == 0 && parsing->zero == 0)
				parsing->zero_flags += 1;
		if (parsing->prec < aff_count && parsing->neg == 1 && parsing->zero == 1)
			parsing->space_flags = parsing->width - ft_strlen(parsing->aff);
	}
	else
	{
		parsing->arg_pos = 1;
		if (parsing->prec != -1)
		{
			if (aff_count < parsing->prec)
				parsing->space_flags += 1;
			else if (parsing->zero == 1 && aff_count > parsing->prec)
				parsing->space_flags -= 1;
		}
	}
	//printf(">>>out neg_prepare3, arg_count is [%d]\n", parsing->arg_count);
}

void	ft_neg_prepare(char *arg, t_parsing *parsing)
{ //printf("what's neg for you ? [%d]\n", parsing->neg);
	int aff_count;

	aff_count = 0;
	if (*arg == 'p' || *arg == 'u')
		ft_neg_prepare2(arg, parsing);
	else if (*arg != 'u' && *arg != 's' && *arg != 'c')
		ft_neg_prepare3(parsing, aff_count);
	if (parsing->prec >= ft_strlen(parsing->aff) && parsing->arg_pos == 1)
	{
		if ((*arg == 'd' || *arg == 'i' || *arg == 'x' || *arg == 'X'))
				parsing->arg_count -= 1;
		if (*arg != 'c' && *arg != 's' && *arg != 'p' && parsing->width == 0)
			parsing->arg_count += 1;
	}
	else if (parsing->prec >= ft_strlen(parsing->aff) && parsing->arg_pos == 0 && parsing->neg == 1)
		if (*arg != 'c' && *arg != 's' && *arg != 'p' && parsing->width == 0)
			parsing->arg_count += 1;
}
