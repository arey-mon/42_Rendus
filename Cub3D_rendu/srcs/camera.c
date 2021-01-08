/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   look.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:40:44 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/09 11:13:00 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../include/cub3d.h"

void	look_right(t_player *p, char c)
{
	c = 0;
	p->dir += M_PI / 40;
	if (p->dir > 2 * M_PI)
		p->dir -= 2 * M_PI;
}

void	look_left(t_player *p, char c)
{
	c = 0;
	p->dir -= M_PI / 40;
	if (p->dir < 0)
		p->dir += 2 * M_PI;
}

void	stay_in_circle(double *d)
{
	if (*d > 2 * M_PI)
		*d -= 2 * M_PI;
	else if (*d < 0)
		*d += 2 * M_PI;
}
