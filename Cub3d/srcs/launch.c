#include "../include/libft.h"
#include "../include/cub3d.h"
#include <mlx.h>
#include <math.h>
#include <X11/Xlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// 3 functions

int	launch_game(t_game *g)
{
	init_moves(g->press, g);
	raycast(g);		
	//	create_image(g);
	g->buf = (float *)malloc(sizeof(float) * g->set.res_x);
        g->dist = (g->set.res_x / 2) / tan(g->p.fov / 2);
	return (0);	
}

void	set_loop(t_game *g, t_img *i)
{

	printf("___ SET_LOOP ___\n");
	mlx_hook(g->win, KeyPress, KeyPressMask, &key_press, &g->press);
	mlx_hook(g->win, KeyRelease, KeyReleaseMask, &key_release, &g->press);
	mlx_hook(g->win, 17, 0, &close_window, &g->press);
	mlx_loop_hook(g->mlx, &launch_game, g);
}

void	launch_image(t_img *i, t_game *g)
{
	printf("_ LAUNCH_IMAGE _\n");
	g->mlx = mlx_init();
	set_res(g, g->set.res_x, g->set.res_y);
	g->win = mlx_new_window(g->mlx, g->set.res_x, g->set.res_y, "CUB3D");
	g->img.img = mlx_new_image(g->mlx, g->set.res_x, g->set.res_y);
	g->img.addr = mlx_get_data_addr(g->img.img, &g->img.bpp, &g->img.size_l, &g->img.endian);
	//g->img.size_l /= 4; 
	set_loop(g, &g->img);
}
