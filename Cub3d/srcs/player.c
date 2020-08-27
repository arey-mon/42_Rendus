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

int	player_starting_dir(char c)
{
	printf("__ PLAYERS_STARTING_DIR __\n");
        double  dir;

        if (c == 'N')
                dir = 3 * M_PI_2;
        else if (c == 'E')
                dir = 0;
        else if (c == 'S')
                dir = M_PI_2;
        else
                dir = M_PI;
	printf("your player dir is : %c, meaning you go to dir : %f\n", c, dir);
	return (dir);	
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
	g->p.dir = player_starting_dir(g->p.nesw);
	g->set.map[x][y] = '0';
}
