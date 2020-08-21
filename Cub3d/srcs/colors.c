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

void	my_mlx_pixel_put(t_img *i, int x, int y, int color)
{
	//printf("_ MY-MLX _\n");
	char    *dst;

	dst = i->addr + (y * i->size_l + x * (i->bpp / 8));
	*(unsigned int*)dst = color;
//	printf(">>>my-mlx out\n");
}

void	get_c_color(t_img *i, t_game *g)
{
	printf("_ GET_C_COLOR _\n");
	printf("i->x is : %d __ i->y is : %d\n", i->x, i->y);
	// first line of pixels seems to be c_f which is not normal
	i->x = 0;
	i->y = 0;
	while (i->x < g->set.res_x)
        {
                my_mlx_pixel_put(i, i->x, i->y, g->set.c_c);
                mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
                i->x++;
        }
	i->x = 0;
	while (i->y < (g->set.res_y / 2))
	{
		my_mlx_pixel_put(i, i->x, i->y, g->set.c_c);
		mlx_put_image_to_window(g->mlx, g->win, g->img.img, i->x, i->y);
		i->y++;
	}
	printf("show c_c value : %d __ and c_f : %d\n", g->set.c_c, g->set.c_f);
	printf("ending c_color with y : %d\n", i->y);
	while (i->y < g->set.res_y)
	{
		my_mlx_pixel_put(i, i->x, i->y, g->set.c_f);
		mlx_put_image_to_window(g->mlx, g->win, g->img.img, i->x, i->y);
		i->y++;
	}
	i->y = 0;
	while (i->x < g->set.res_x)
        {
                my_mlx_pixel_put(i, i->x, i->y, g->set.c_f);
                mlx_put_image_to_window(g->mlx, g->win, g->img.img, i->x, i->y);
                i->x++;
        }
	printf(">>>\n");
}
