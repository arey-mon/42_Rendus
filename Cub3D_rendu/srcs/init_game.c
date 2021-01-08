/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:13:47 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/11 12:04:01 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <math.h>
#include "../include/cub3d.h"
#include "../libft/libft.h"

void		set_res(t_game *g, int x, int y)
{
	mlx_get_screen_size(g->mlx_ptr, &x, &y);
	if (g->set.res_x > x)
		g->set.res_x = x;
	if (g->set.res_y > y)
		g->set.res_y = y;
}

static void	init_img(t_img *i, t_game *g)
{
	void	*p;

	g->mlx_ptr = mlx_init();
	set_res(g, g->set.res_x, g->set.res_y);
	g->img.y = g->set.res_y;
	g->img.x = g->set.res_x;
	if (g->screenshot_off == 0)
		g->win_ptr = mlx_new_window(g->mlx_ptr, g->set.res_x,
				g->set.res_y, "Cub3D");
	i->ptr = mlx_new_image(g->mlx_ptr, g->set.res_x, g->set.res_y);
	p = i->ptr;
	i->d_ptr = (int *)mlx_get_data_addr(p, &i->bpp, &i->size_l, &i->endian);
	i->size_l /= 4;
	set_hooks(g);
}

void		init_game(t_game *g)
{
	init_player(g);
	init_img(&(g->img), g);
	init_text(g);
	init_sprite(g, g->set);
	g->buf = (float *)malloc(sizeof(float) * g->set.res_x);
	g->s_dist = (g->set.res_x / 2) / tan(g->p.fov / 2);
}
