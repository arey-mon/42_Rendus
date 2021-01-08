/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 13:43:50 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/06 10:36:39 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	draw_fov(t_game g)
{
	double dir;
	double i;

	dir = g.p.dir - M_PI / 6;
	i = g.p.fov / g.set.res_x;
	while (dir <= g.p.dir + M_PI / 6)
	{
		draw_line(g.img, g.p, dir, 10 * get_dist(g, dir, &g.r));
		dir += i;
	}
}

void	draw_map(t_game g)
{
	int x;
	int y;
	int s;

	y = 0;
	s = BLOCK_MAP;
	while (y < g.set.map_y)
	{
		x = 0;
		while (x < g.set.map_x)
		{
			if (g.set.map[y][x] == '0')
				draw_square(g.img, 0, x * s, y * s);
			else if (g.set.map[y][x] == '1')
				draw_square(g.img, 12020, x * s, y * s);
			x++;
		}
		y++;
		draw_fov(g);
	}
}
