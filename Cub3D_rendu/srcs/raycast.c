/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/09 16:51:50 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/10 13:35:47 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/cub3d.h"
#include "../libft/libft.h"

int		collision(t_game *g, float x, float y)
{
	if (g->r.d > M_PI && g->r.d <= 2 * M_PI)
		y = (int)y - 1;
	else
		y = (int)y;
	if (g->r.d > M_PI_2 && g->r.d < 3 * M_PI_2)
		x = (int)x - 1;
	else
		x = (int)x;
	return (g->set.map[(int)y][(int)x] - '0');
}

float	get_dist(t_game *g, double d, t_ray *r)
{
	r->d = d;
	r->h = get_wall_h(g, r);
	r->v = get_wall_v(g, r);
	r->side = r->h >= r->v ? 0 : 1;
	if (!g->press.aim)
		return (r->side == 0 ? r->v : r->h);
	else
		return (r->side == 0 ? r->v / 2 : r->h / 2);
}

void	raycast(t_game g)
{
	int		j;
	double	i;
	double	d;
	float	dist;

	if (g.press.aim)
		g.p.fov /= 2;
	j = 0;
	i = g.p.fov / g.set.res_x;
	d = g.p.dir - g.p.fov / 2;
	while (j < g.set.res_x)
	{
		stay_in_circle(&d);
		dist = get_dist(&g, d, &g.r);
		draw_column(g, dist, j);
		g.buf[j++] = dist;
		d += i;
	}
	draw_sprite(&g);
}
