#include "../include/libft.h"
#include "../include/cub3d.h"
#include <mlx.h>
#include <stdio.h>

int     close_window(int key, t_game g)
{
        printf("__ CLOSE_WINDOW __\n");
	printf("value of press.quit is :%c\n", g.press.quit);
	if (key == ESC)
        {
		g.press.quit = '1';
		printf("you touched ESCAPE\n");
	// not a structure or pointer union, syntax or recode...?
	//mlx_destroy_image(g->mlx, (*g).txt[0].tmp);
	 // mlx_destroy_image(g->mlx, g->img.tmp);
	 // mlx_destroy_window(g->mlx, g->win);
         // closes the window but actually creates a segfault
	 // tried to put it in exit_clean but same pb
		exit_clean(0, &g);
        }
        return (0);
}

int     exit_clean(int err, t_game *g)
{
        char    **msg;
	int	i;

	i = 0;
        printf("___ EXIT_CLEAN ___\n");
        if (err > 0)
		ft_putstr_fd("Error\n", 1);
        msg = err_msg();
        ft_putstr_fd(msg[err], 1);
        free(msg);
	exit(0);
        return (0);
}

char    **err_msg()
{
        printf("__ ERR_MSG __\n");
        char    **msg;
        if (!(msg = ft_calloc(sizeof(char *), 20)))
                return (NULL);
        msg[0] = "Finishing program\n"; // Not sure it's OK if printed
        msg[INV_FD] = "File is invalid\n";
        msg[INV_RES] = "Resolution is invalid\n";
        msg[INV_EXT] = "Extension is invalid\n";
        msg[INV_RGB] = "RGB is invalid\n";
        msg[INV_MAP] = "Map is invalid\n";
        msg[INV_PLAYER] = "Player position is invalid\n";
        return (msg);
}
