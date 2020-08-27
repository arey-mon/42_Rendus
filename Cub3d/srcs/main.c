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

void	load_txt(t_img *i, t_game g, char *path)
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
	load_txt(&(g->txt[0]), *g, g->set.t_n);
        load_txt(&(g->txt[1]), *g, g->set.t_e);
        load_txt(&(g->txt[2]), *g, g->set.t_s);
        load_txt(&(g->txt[3]), *g, g->set.t_w);
        load_txt(&(g->txt[4]), *g, g->set.t_sp);
}

void	create_image(t_game *g)
{
	printf("___ CREATE_IMAGE ___\n");
	get_c_color(&g->img, g);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, 0, 0);
}

void	raycast(t_game *g)
{
	printf(" ");
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
//	launch_textures(g);	
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
