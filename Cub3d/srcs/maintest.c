#include "../include/libft.h"
#include "../include/cub3d.h"
#include <mlx.h>
#include <X11/Xlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	exit_clean(int err, t_game *g)
{
	char	**msg;
        printf("___ EXIT_CLEAN ___\n");
	ft_putstr_fd("Error\n", 1);
	msg = err_msg();
	ft_putstr_fd(msg[err], 1);
	exit(0);
	return (0);
}

char	**err_msg()
{
	char	**msg;
	printf("__ ERR_MSG __\n");
	if (!(msg = ft_calloc(sizeof(char *), 20)))
		return (NULL);
	msg[INV_FD] = "File is invalid\n";
	msg[INV_RES] = "Resolution is invalid\n";
	msg[INV_EXT] = "Extension is invalid\n";
	msg[INV_RGB] = "RGB is invalid\n";
	return (msg);
}

void    set_res(t_game *g, int x, int y)
{
	int a;
	int z;

	printf("_ SET RES _\n");
	mlx_get_screen_size(g->mlx, &a, &z);
        if (g->set.res_x > a)
                g->set.res_x = a;
        if (g->set.res_y > z)
                g->set.res_y = z;
        printf("x was : %d __ res_x is : %d\ny was : %d __ res_y is : %d\n", x, g->set.res_x, y, g->set.res_y);
}

void	set_loop(t_game *g)
{
	printf("___ SET_LOOP ___\n");
	init_touches(g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &key_press, g);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &key_release, g);
	mlx_loop(g->mlx);
}

void	set_game(t_game *g)
{
	printf("_ SET GAME _\n");
	g->mlx = mlx_init();
	set_res(g, g->set.res_x, g->set.res_y);
	g->win = mlx_new_window(g->mlx, g->set.res_x, g->set.res_y, "CUB");
	g->img.tmp = mlx_new_image(g->mlx, g->set.res_x, g->set.res_y);
	g->img.data = (int *)mlx_get_data_addr(g->mlx, &g->img.bpp, &g->img.size_l, &g->img.endian);
/*
	printf("data from *img stocks : %d\n", g->img.bpp);
	printf("data from *img stocks : %d\n", g->img.size_l);
	printf("data from *img stocks : %d\n", g->img.endian);
*/
	set_loop(g);
}

int	main(int ac, char **av)
{
	int	err;
	t_game	g;

	if (ac < 2 || (err = check_ext(av[1])))
		exit_clean(err, &g);
	get_settings(&g.set, open(av[1], O_RDONLY));
	err = parse_fd_check(&g.set);
	(err == 0) ? set_game(&g) : exit_clean(err, &g);
	printf("err is : %d __ program finishing OK\n", err);
}
