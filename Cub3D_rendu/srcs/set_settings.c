/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_settings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 16:41:19 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/23 12:46:01 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

int		convert_color(int *rgb)
{
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	get_color(int *set, char *str)
{
	set[0] = ft_atoi(++str);
	while (*str != ',')
	{
		if (!ft_isdigit(*str) && *str != ' ')
			set[0] = -1;
		str++;
	}
	set[1] = ft_atoi(++str);
	while (*str != ',')
	{
		if (!ft_isdigit(*str) && *str != ' ')
			set[1] = -1;
		str++;
	}
	set[2] = ft_atoi(++str);
}

char	*get_text(char *str)
{
	while (*str == ' ')
		str++;
	return (ft_strdup(str));
}

void	get_res(int *res_x, int *res_y, char *str)
{
	*res_x = ft_atoi(++str);
	while (*str == ' ')
		str++;
	while (*str >= '0' && *str <= '9')
		str++;
	*res_y = ft_atoi(str);
}

void	init_rgb(t_settings *set)
{
	if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
		return ;
	if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
		return ;
}
