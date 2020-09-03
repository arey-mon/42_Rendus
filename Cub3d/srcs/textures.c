#include "../include/libft.h"
#include "../include/cub3d.h"
#include <mlx.h>
#include <math.h>
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
