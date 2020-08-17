#include "../include/libft.h"
#include "../include/cub3d.h"
#include <mlx.h>
#include <stdio.h>

int     close_window(int key, t_game *g)
{
        int err;

        err = key;
        printf("__ CLOSE_WINDOW __\n");
        if (key == ESC)
        {
		mlx_destroy_window(g->mlx, g->win);
         // closes the window but actually creates a segfault
	 // tried to put it in exit_clean but same pb
		exit_clean(err, g);
        }
        return (0);
}

int     exit_clean(int err, t_game *g)
{
        char    **msg;
        printf("___ EXIT_CLEAN ___\n");
        ft_putstr_fd("Error\n", 1);
        msg = err_msg();
        ft_putstr_fd(msg[err], 1);
        exit(0);
        return (0);
}

char    **err_msg()
{
        char    **msg;
        printf("__ ERR_MSG __\n");
        if (!(msg = ft_calloc(sizeof(char *), 20)))
                return (NULL);
        msg[INV_FD] = "File is invalid\n";
        msg[INV_RES] = "Resolution is invalid\n";
        msg[INV_EXT] = "Extension is invalid\n";
        msg[INV_RGB] = "RGB is invalid\n";
        msg[INV_MAP] = "Map is invalid\n";
        msg[INV_PLAYER] = "Player position is invalid\n";
        return (msg);
}

