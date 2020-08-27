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

void    get_rgb_malloc(t_settings *set)
{
        printf("___ INIT_RGB ___\n");
        if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
                return ;
        if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
                return ;
}

void    get_fc_color(int *rgb, char *s)
{
        printf("___ GET_FC_COLOR\n");
        int i;

        i = 0;
        rgb[i] = ft_atoi(++s);
        i += 1;
        while (*s != ',')
                s++;
        rgb[i] = ft_atoi(++s);
        i += 1;
        while (*s != ',')
                s++;
        rgb[i] = ft_atoi(++s);
        printf("results are rgb[0] == %d _ rgb[0] == %d _ rgb[0] == %d\n", rgb[0], rgb[1], rgb[2]);
}
