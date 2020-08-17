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

void	my_mlx_pixel_put(t_img *i, int x, int y, int color)
{
	char    *dst;

	dst = i->addr + (y * i->size_l + x * (i->bpp / 8));
	*(unsigned int*)dst = color;
}

void	get_c_color(t_img *i, t_game *g)
{
        while (i->x < g->set.res_x)
        {
                my_mlx_pixel_put(i, i->x, i->y, g->set.c_c);
                mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
                i->x++;
        }
        i->x = 0;
        printf("i->y is : %d\n", i->y);
	while (i->y < g->set.res_y)
        {
		if (i->y >= (g->set.res_y / 2))
			my_mlx_pixel_put(i, i->x, i->y, g->set.c_f);
		else
			my_mlx_pixel_put(i, i->x, i->y, g->set.c_c);
		mlx_put_image_to_window(g->mlx, g->win, g->img.img, i->x, i->y);
                i->y++;
        }
}

void	launch_textures(t_game *g)
{
	printf("_ LAUNCH_TEXTURES _\n");
	printf("show me g->t_n : %s t_s : %s\n", g->set.t_n, g->set.t_s);
	printf("your x is : %d __ your y is : %d\n", g->img.x, g->img.y);
	g->img.x = 0;
	g->img.y = 0;
	g->img.img = mlx_xpm_file_to_image(g->mlx, g->set.t_n, &g->img.x, &g->img.y);
	g->img.tmp = mlx_new_image(g->mlx, g->img.x, g->img.y);
	printf("your x is : %d __ your y is : %d\n", g->img.x, g->img.y);
	printf("value of img is : %s\n", g->img.img);
}

void	launch_image(t_img *i, t_game *g)
{
	printf("_ LAUNCH_IMAGE _\n");
	//get_c_color(i, g);
	launch_player(g);
	launch_textures(g);	
}

void	set_loop(t_game *g, t_img *i)
{
	printf("___ SET_LOOP ___\n");
	init_touches(g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &key_press, g);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &key_release, g);
	mlx_hook(g->win, KeyPress, KeyPressMask, &close_window, &(g->img));
	launch_image(i, g);
	mlx_loop(g->mlx);
}

void	set_game(t_game *g)
{
	// to see better
	g->set.res_x /= 2;
	g->set.res_y /= 2;
	
	printf("_ SET GAME _\n");
	g->mlx = mlx_init();
	set_res(g, g->set.res_x, g->set.res_y);
	g->win = mlx_new_window(g->mlx, g->set.res_x, g->set.res_y, "CUB3D");
	g->img.img = mlx_new_image(g->mlx, g->set.res_x, g->set.res_y);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.size_l, &g->img.endian);
	g->img.size_l /= 4; 
	// allow to set byte line per line instead of in cross
	set_loop(g, &g->img);
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
