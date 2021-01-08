/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/15 14:18:45 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/10 11:29:49 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <math.h>

void	move_front(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x + cos(p->dir) * SPEED;
	y = p->y + sin(p->dir) * SPEED;
	if (collision(g, x, p->y) != 1)
		p->x = x;
	if (collision(g, p->x, y) != 1)
		p->y = y;
}

void	move_back(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x - cos(p->dir) * SPEED;
	y = p->y - sin(p->dir) * SPEED;
	if (collision(g, x, p->y) != 1)
		p->x = x;
	if (collision(g, p->x, y) != 1)
		p->y = y;
}

void	move_left(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x + sin(p->dir) * SPEED;
	y = p->y - cos(p->dir) * SPEED;
	if (collision(g, x, p->y) != 1)
		p->x = x;
	if (collision(g, p->x, y) != 1)
		p->y = y;
}

void	move_right(t_player *p, t_game *g)
{
	float x;
	float y;

	x = p->x - sin(p->dir) * SPEED;
	y = p->y + cos(p->dir) * SPEED;
	if (collision(g, x, p->y) != 1)
		p->x = x;
	if (collision(g, p->x, y) != 1)
		p->y = y;
}

int		init_moves(t_game *game)
{
	if (game->press.quit)
		clean_exit(0, game);
	if (game->press.w)
		move_front(&game->p, game);
	if (game->press.d)
		move_right(&game->p, game);
	if (game->press.s)
		move_back(&game->p, game);
	if (game->press.a)
		move_left(&game->p, game);
	if (game->press.right)
		look_right(&game->p, 0);
	if (game->press.left)
		look_left(&game->p, 0);
	return (0);
}
