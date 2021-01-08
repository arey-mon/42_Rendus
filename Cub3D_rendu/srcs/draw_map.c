/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/21 09:16:05 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/10 13:34:52 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	draw_square(t_img img, int c, int x, int y)
{
	int	i;
	int	j;

	j = 0;
	while (j <= img.index)
	{
		i = 0;
		while (i <= img.index)
			img.d_ptr[(j + y) * (img.size_l) + x + i++] = c;
		j++;
	}
}

void	draw_ray(t_img i, t_player p, double dir, int d)
{
	while (d--)
	{
		p.x += cos(dir);
		p.y += sin(dir);
		i.d_ptr[(int)(p.y) * i.size_l + (int)(p.x)] = 0xffffff;
	}
}

void	draw_line(t_img *i, int x, int y, int dist)
{
	int	*img;

	img = i->d_ptr;
	img += y * i->size_l + x;
	while (dist--)
		*(img++) = 0xc0c0c0;
}
