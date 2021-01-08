/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 12:37:57 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/12 17:52:52 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static int	check_color(int *x, int *y)
{
	if (0 > x[0] || x[0] > 255 || 0 > x[1] || x[1] > 255 ||
			0 > x[2] || x[2] > 255)
		return (1);
	if (0 > y[0] || y[0] > 255 || 0 > y[1] || y[1] > 255 ||
			0 > y[2] || y[2] > 255)
		return (1);
	return (0);
}

static int	check_res(int x, int y)
{
	if (x <= 0 || y <= 0)
		return (1);
	return (0);
}

int			check_file(char *s)
{
	int		fd;
	int		ret;
	char	s2[10];

	fd = open(s, O_RDONLY);
	ret = read(fd, &s2, 10);
	close(fd);
	if (ret <= 0)
		return (1);
	return (0);
}

int			check_map_init(char **map, int *map_y, int *map_x, int i)
{
	int		map_w;
	t_game	*g;

	g = NULL;
	map_w = 0;
	i = 0;
	*map_x = 0;
	*map_y = 0;
	while (map[map_w])
		map_w++;
	if (check_ends(map[0]) || check_ends(map[map_w - 1]))
	{
		clean_exit(3, g);
		return (INV_MAP);
	}
	*map_y = map_w;
	return (0);
}

int			parse(t_settings *set)
{
	int	i;

	i = 0;
	if (check_res(set->res_x, set->res_y))
		return (INV_RES);
	if (check_file(set->t_n) || check_file(set->t_e) ||
			check_file(set->t_s) || check_file(set->t_w))
		return (INV_PATH);
	if (check_file(set->t_sp))
		return (INV_SP);
	if (check_color(set->rgb_f, set->rgb_c))
	{
		free(set->rgb_f);
		free(set->rgb_c);
		return (INV_CLR);
	}
	set->c_c = convert_color(set->rgb_c);
	set->c_f = convert_color(set->rgb_f);
	free(set->rgb_f);
	free(set->rgb_c);
	check_map_init(&set->map[i], &set->map_y, &set->map_x, i);
	return (check_map(set->map, &set->map_x, &set->map_y, i));
}
