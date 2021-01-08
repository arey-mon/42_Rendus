/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 16:14:38 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/11 11:53:07 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <mlx.h>
#include <X11/Xlib.h>

int		key_press(int key, t_input *press)
{
	if (key == MV_F)
		press->w = 1;
	if (key == MV_R)
		press->d = 1;
	if (key == MV_B)
		press->s = 1;
	if (key == MV_L)
		press->a = 1;
	if (key == LOOK_R)
		press->right = 1;
	if (key == LOOK_L)
		press->left = 1;
	if (key == ESC)
		press->quit = 1;
	return (0);
}

int		key_release(int key, t_input *press)
{
	if (key == MV_F)
		press->w = 0;
	if (key == MV_R)
		press->d = 0;
	if (key == MV_B)
		press->s = 0;
	if (key == MV_L)
		press->a = 0;
	if (key == LOOK_R)
		press->right = 0;
	if (key == LOOK_L)
		press->left = 0;
	return (0);
}

void	init_keyboard(t_input *press)
{
	press->w = 0;
	press->d = 0;
	press->s = 0;
	press->a = 0;
	press->right = 0;
	press->left = 0;
	press->quit = 0;
}
