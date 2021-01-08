/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:16:05 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/10 13:34:52 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>
#include <mlx.h>

void			load_txt(t_img *t, t_game g, char *path)
{
	int	*p;

	t->ptr = mlx_xpm_file_to_image(g.mlx_ptr, path, &t->x, &t->y);
	p = (int *)mlx_get_data_addr(t->ptr, &t->bpp, &t->size_l, &t->endian);
	t->d_ptr = p;
	t->size_l /= 4;
}

void			init_text(t_game *g)
{
	load_txt(&(g->txt[0]), *g, g->set.t_n);
	load_txt(&(g->txt[1]), *g, g->set.t_w);
	load_txt(&(g->txt[2]), *g, g->set.t_s);
	load_txt(&(g->txt[3]), *g, g->set.t_e);
	load_txt(&(g->txt[4]), *g, g->set.t_sp);
}

unsigned int	get_txt_color(t_img t, int x, int y)
{
	return (t.d_ptr[x + (y * t.size_l)]);
}

t_img			select_text(t_game g)
{
	if (g.r.side == 1)
		return (g.r.d > M_PI ? g.txt[0] : g.txt[2]);
	else
		return (g.r.d > M_PI_2 && g.r.d < 3 * M_PI_2 ? g.txt[1] : g.txt[3]);
}
