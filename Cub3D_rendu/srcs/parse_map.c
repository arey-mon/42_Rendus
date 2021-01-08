/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 11:20:16 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/12 20:12:52 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>

int		check_ends(char *s)
{
	while (*s)
	{
		while (*s == ' ')
			s++;
		if (*s != '1' && *s != '\0')
			return (1);
		while (*s == '1')
			s++;
		if (*s != ' ' && *s != '\0')
			return (1);
		if (*s == '\n' && *(s - 1) != '1')
			return (1);
	}
	return (0);
}

int		get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	return (i);
}

int		check_map(char **map, int *map_x, int *map_y, int i)
{
	int	*tmp;

	if (!(tmp = (int *)malloc(sizeof(int) * (*map_y))))
		return (INV_MAP);
	while (i < *map_y)
	{
		if (check_map_line(map[i], &tmp[i]))
		{
			free(tmp);
			return (INV_CUB);
		}
		if (tmp[i++] > *map_x)
			*map_x = tmp[i - 1];
	}
	i = 0;
	while (i < *map_x)
	{
		if (check_map_col(map, tmp, i++))
		{
			free(tmp);
			return (INV_CUB);
		}
	}
	free(tmp);
	return (0);
}
