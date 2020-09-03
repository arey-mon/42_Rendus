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

void	draw_wall(t_game *g, int x, int y)
{
	x = 0;
	while (x < g->set.res_x)
	{
		my_mlx_pixel_put(&g->img, x, y,  0xFFFFFFFF);
		mlx_put_image_to_window(g->mlx, g->win, g->img.img, g->img.x, g->img.y);
		x++;
	}
	int y2 = y - g->ray.wall_h;
	while (y2 < y)
	{
		my_mlx_pixel_put(&g->img, x, y,  0xFFFFFFFF);
		mlx_put_image_to_window(g->mlx, g->win, g->img.img, g->img.x, g->img.y);
		y2++;
	}
}

void	color_cf(t_game *g)
{
	double	wall_h;
	double	f;
	char	*tmp;
	int	y;
	int	x;

	g->ray.wall_h = 0;
	x = g->set.res_x; // it's not right, x should be fluctuant but how..?
	y = 0;
	g->ray.wall_h = BLOCK_SIZE / g->ray.wall_dist * g->dist;
//	printf("your g->dist is %d\n", g->dist);
	printf("wall_h is : %f\n", g->ray.wall_h);
	f = (g->img.y - wall_h) / 2;
	printf("wall_dist is : %f\n", g->ray.wall_dist);
//	printf("g->img.y is : %d\n", g->img.y);
//	printf("g->img.size_l is : %d\n", g->img.size_l); printf("f is : %f\n", f);  printf("x is : %d\n", x);
	while (y < f)
	{
		tmp = &g->img.addr[y++ * g->img.size_l + x];
		*(unsigned int*)tmp = g->set.c_c;
	}
	y += wall_h;
	draw_wall(g, x, y);
	while (y < g->set.res_y)
	{
		tmp = &g->img.addr[y++ * g->img.size_l + x];
		*(unsigned int*) tmp = g->set.c_f;
	}
}

void	create_image(t_game *g)
{
	printf("___ CREATE_IMAGE ___\n");
	g->img.y = g->set.res_y;
	g->img.x = g->set.res_x;
	
	color_cf(g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	raycast(t_game *g)
{
	t_ray	ray;

	g->ray.wall_dist = g->p.dir - g->p.fov / 2;
	create_image(g);
	printf(" ");
}

void	set_game(t_game *g)
{
	// to see better
	g->set.res_x /= 1.5;
	g->set.res_y /= 1.5;
	
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
	mlx_loop(g.mlx);
}
