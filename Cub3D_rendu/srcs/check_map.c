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

int			check_map_line(char *str, int *width)
{
	int			i;
	static char	charset[8] = {'0', '1', '2', 'N', 'E', 'S', 'W', '\0'};

	i = 0;
	while (str[i])
	{
		while (str[i] == ' ')
			i++;
		if (str[i] != '1' && str[i] != '\0')
			return (1);
		while (str[i] && in_set(str[i], charset))
			i++;
		if (str[i] != ' ' && str[i] != '\0')
			return (1);
		else if (str[i] == ' ' && str[i - 1] != '1')
			return (1);
	}
	*width = i;
	return (0);
}

static int	col_inset(char **map, int i, int x, int *width)
{
	static char	charset[8] = {'0', '1', '2', 'N', 'E', 'S', 'W', '\0'};

	while ((map[i][x] == ' ') || (in_set(map[i][x], charset)))
	{
		if (map[i][x] == ' ')
		{
			if (x == 0)
				while (map[i][x] == ' ')
					x++;
			else
			{
				if ((i != 0 && width[i - 1] > x
							&& (map[i - 1][x] != '1' && map[i - 1][x] != ' '))
						|| (map[i + 1][x] != '1' && map[i + 1][x] != ' '))
				{
					x = -1;
					break ;
				}
			}
		}
		x++;
	}
	return (x);
}

int			check_map_col(char **map, int *width, int x)
{
	int			i;
	int			height;

	i = 0;
	x = 0;
	height = get_height(map);
	while (i < (height - 1))
	{
		x = col_inset(map, i, x, width);
		if (x < 0)
			return (1);
		if (x == width[i])
		{
			i++;
			if (i < (height - 2))
				x = 0;
		}
	}
	return (0);
}
