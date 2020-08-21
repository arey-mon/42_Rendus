#include "../include/libft.h"
#include "../include/cub3d.h"
#include "mlx.h"
#include <stdio.h>
#include <math.h>

int	player_pos(char **map, int *x, int *y)
{
	printf("___ PLAYER-POS___\n");
	while (map[*x])
	{
		while (map[*y])
		{
		
			if (map[*x][*y] == 'N' || map[*x][*y] == 'E'
			|| map[*x][*y] == 'S' || map[*x][*y] == 'W')
			{
				printf("Player NSEW has been found, his coordonates are :\nmap[*x] == %d\nmap[*y] == %d\n", *x, *y);
				return (0);
			}
		(*y)++;
		}
	*y = 1;
	(*x)++;
	}
	return (1);
}

void	player_starting_dir(t_game *g, int x, int y)
{
	// it will be used to know player starting direction
	// have to change int color for it to be seen
	// my_mlx_pixel_put(&g->img, x, y, g->set.c_c);
	mlx_put_image_to_window(g->mlx, g->win, g->img.img, x, y);

}

void	launch_player(t_game *g)
{
	printf("___ LAUNCH-PLAYER___\n");
	int	x;
	int	y;

	x = 1;
	y = 1;
	if (player_pos(g->set.map, &x, &y) == 1)
		exit_clean(6, g);
	g->p.x = x;	
	g->p.y = y;
	g->p.fov = M_PI / 3;
	g->p.nesw = g->set.map[x][y]; // is getting first direction from map
	printf("your nesw is : %c\n", g->p.nesw);
	//player_starting_dir(g, &x, &y);
}
