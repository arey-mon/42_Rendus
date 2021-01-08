/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 13:13:47 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/11 12:04:01 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <X11/Xlib.h>
#include <math.h>
#include <mlx.h>
#include "../include/cub3d.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

int		game_loop(t_game *g)
{
	init_moves(g);
	raycast(*g);
	if (g->screenshot_off == 0)
		draw_window(g);
	return (0);
}

void	set_hooks(t_game *g)
{
	if (g->screenshot_off == 0)
	{
		init_keyboard(&g->press);
		mlx_hook(g->win_ptr, KeyPress, KeyPressMask, &key_press, &g->press);
		mlx_hook(g->win_ptr, KeyRelease, KeyReleaseMask, &key_release,
				&g->press);
		mlx_hook(g->win_ptr, 33, 0, &clean_exit, &g->press);
		mlx_loop_hook(g->mlx_ptr, &game_loop, g);
	}
}

int		check_ext(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	i -= 1;
	while (s[i] == ' ')
		i--;
	if (s[i] != 'b' || s[i - 1] != 'u' || s[i - 2] != 'c' || s[i - 3] != '.')
		return (INV_EXT);
	return (0);
}

int		main(int ac, char **av)
{
	t_game	game;
	int		err;

	game.screenshot_off = 0;
	err = 0;
	if (ac < 2 || (err = check_ext(av[1])))
		ac < 2 ? clean_exit(1, &game) : clean_exit(INV_EXT, &game);
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
		game.screenshot_off = 1;
	else if (ac == 3 && ft_strcmp(av[2], "--save") != 0)
	{
		clean_exit(1, &game);
		return (0);
	}
	get_settings(&game, &game.set, open(av[1], O_RDONLY));
	err = parse(&game.set);
	(err == 0) ? init_game(&game) : clean_exit(err, &game);
	game.set.map[(int)game.p.y][(int)game.p.x] = '0';
	if (ac == 3 && !ft_strcmp(av[2], "--save"))
	{
		raycast(game);
		screenshot(game.img, game);
	}
	mlx_loop(game.mlx_ptr);
	return (0);
}
