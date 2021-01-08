/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 12:11:43 by apreymon          #+#    #+#             */
/*   Updated: 2020/05/12 19:05:29 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../libft/libft.h"
#include <stdlib.h>
#include <mlx.h>

static void	map_free(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
}

static void	txt_free(t_game *g)
{
	mlx_destroy_image(g->mlx_ptr, g->txt[0].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[1].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[2].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[3].ptr);
	mlx_destroy_image(g->mlx_ptr, g->txt[4].ptr);
	mlx_destroy_image(g->mlx_ptr, g->img.ptr);
}

static char	**init_err_msg(void)
{
	char	**msg;

	if (!(msg = ft_calloc(sizeof(char *), 14)))
		return (NULL);
	msg[0] = "";
	msg[NO_ARG] = "Argument is wrong\n";
	msg[INV_EXT] = "Extension is not .cub\n";
	msg[INV_CUB] = "Map is invalid\n";
	msg[INV_FD] = "File does not exist\n";
	msg[INV_RES] = "Invalid screen resolution.\n";
	msg[INV_PATH] = "Wrong texture path.\n";
	msg[INV_SP] = "Wrong sprite texture path.\n";
	msg[INV_CLR] = "Invalid color.\n";
	msg[INV_MAP] = "Invalid map.\n";
	msg[MULT_PLA] = "Multiple player starting point.\n";
	msg[INV_PLA] = "No player on the map.\n";
	msg[INV_SYN] = "Map format is invalid.\n";
	msg[ERR_XX] = "";
	return (msg);
}

int			clean_exit(int err, t_game *g)
{
	char	**msg;

	if (err < 0 || err > 13)
		err = ERR_XX;
	if (err == 0)
	{
		txt_free(g);
		map_free(g->set.map);
		free(g->buf);
		exit(0);
	}
	msg = init_err_msg();
	if (err > 4 && err != ERR_XX && err != 13)
		map_free(g->set.map);
	if (err != ERR_XX)
		ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg[err], 1);
	free(msg);
	exit(0);
	return (0);
}
