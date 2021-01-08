/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 12:16:33 by apreymon          #+#    #+#             */
/*   Updated: 2020/07/10 14:37:25 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>
#include <stdlib.h>

static double	set_dir(char c)
{
	double	dir;

	if (c == 'N')
		dir = 3 * M_PI_2;
	else if (c == 'E')
		dir = 0;
	else if (c == 'S')
		dir = M_PI_2;
	else
		dir = M_PI;
	return (dir);
}

static int		get_pos_player(char **map, int *i, int *j)
{
	while (map[*i])
	{
		while (map[*i][*j])
		{
			if (in_set(map[*i][*j], "NESW"))
				return (1);
			(*j)++;
		}
		*j = 1;
		(*i)++;
	}
	return (0);
}

void			init_player(t_game *g)
{
	int			i;
	int			j;

	i = 1;
	j = 1;
	if (!(get_pos_player(g->set.map, &i, &j)))
		clean_exit(11, g);
	g->p.x = j + 0.5;
	g->p.y = i + 0.5;
	g->p.dir = set_dir(g->set.map[i][j]);
	g->set.map[i][j] = '0';
	g->p.fov = M_PI / 3;
	if (get_pos_player(g->set.map, &i, &j))
		clean_exit(13, g);
}
