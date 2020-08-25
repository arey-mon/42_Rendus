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

/*
void	txt_in_tab(t_game *g)
{
	g->txt[0] = g->set.t_n;
	g->txt[1] = g->set.t_e;
	g->txt[2] = g->set.t_s;
	g->txt[3] = g->set.t_w;
	g->txt[4] = g->set.t_sp;
	g->txt[5] = "\0";
	printf(">>> out of txt_in_tab\n");
}
*/

void            load_txt(t_img *i, t_game g, char *path)
{
	char	*tmp_addr;

        i->tmp = mlx_xpm_file_to_image(g.mlx, path, &i->x, &i->y);
        tmp_addr = mlx_get_data_addr(i->tmp, &i->bpp, &i->size_l, &i->endian);
        i->addr = tmp_addr;
        i->size_l /= 4;
}

void	launch_textures(t_game *g)
{
	printf("_ LAUNCH_TEXTURES _\n");
	//txt_in_tab(g);
	load_txt(&(g->txt[0]), *g, g->set.t_n);
        load_txt(&(g->txt[1]), *g, g->set.t_e);
        load_txt(&(g->txt[2]), *g, g->set.t_s);
        load_txt(&(g->txt[3]), *g, g->set.t_w);
        load_txt(&(g->txt[4]), *g, g->set.t_sp);
	
	printf("value of img is : %s\n", g->img.img);
}

void	create_image(t_game *g)
{
	printf("___ CREATE_IMAGE ___\n");
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	raycast(t_game *g)
{
	int	x;

	x = 0;
	while (x < g->set.res_x)
	{
	//	get_c_color(&g->img, g);
		printf("we're all good\n");
	}
}

int	launch_game(int key, t_game *g)
{
	//printf("___ LAUNCH_GAME ___\n");
	if (key == ESC)
		exit_clean(0, g);
	// this printf alone creates a segfault
	//printf("do you receive g->press : %d\n", g->press.quit);
	/*	
	if (g->press.quit != 0)
	{
		printf("press.quit is == 1, we quit\n");
		exit_clean(0, g);
	}
	else */
	{
		//init_moves
//		raycast(g);
	//	create_image(g);
	}
	return (0);	
}

void	set_loop(t_game *g, t_img *i)
{

	printf("___ SET_LOOP ___\n");
	mlx_hook(g->win, KeyPress, KeyPressMask, &key_press, &g->press);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &key_release, &g->press);
	mlx_hook(g->win, 17, 0, &close_window, &g->press);
	mlx_loop_hook(g->mlx, &launch_game, g);
	mlx_loop(g->mlx);
}

void	launch_image(t_img *i, t_game *g)
{
	printf("_ LAUNCH_IMAGE _\n");
	g->mlx = mlx_init();
	set_res(g, g->set.res_x, g->set.res_y);
	g->win = mlx_new_window(g->mlx, g->set.res_x, g->set.res_y, "CUB3D");
	g->img.img = mlx_new_image(g->mlx, g->set.res_x, g->set.res_y);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.size_l, &g->img.endian);
	get_c_color(i, g); // to be put later in raycasting
	//g->img.size_l /= 4; 
	set_loop(g, &g->img);
}

void	set_game(t_game *g)
{
	// to see better
	//g->set.res_x /= 2;
	//g->set.res_y /= 2;
	
	printf("_ SET GAME _\n");
	init_touches(g);
	launch_player(g);
	launch_image(&g->img, g);
	launch_textures(g);	
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
