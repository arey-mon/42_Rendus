#include "../include/cub3d.h"
#include <mlx.h>
#include <X11/Xlib.h>
#include <stdio.h>

// 3 Functions

void    init_touches(t_game *g)
{
        g->press.l = 0;
        g->press.r = 0;
        g->press.f = 0;
        g->press.b = 0;
        g->press.quit = 0;
}

int     key_release(t_game *g)
{
        printf("___ KEY_RELEASE ___\n");
        int key;

        if (key == MV_F)
                g->press.f = 0;
        if (key == MV_B)
                g->press.b = 0;
        if (key == MV_L)
                g->press.l = 0;
        if (key == MV_R)
                g->press.l = 0;
        //looking left, right etc will happen here also
        //ESC key might also be here
        return (0);
}

int     key_press(t_press *press) 
{
        printf("___ KEY_PRESS ___\n");
        int	key;
	int	err;

        if (key == MV_F)
        {   
                printf("MV_F key has been touched, gross ! \n");
                press->f = 1;
        }   
        if (key == MV_B)
                press->b = 1;
        if (key == MV_L)
                press->l = 1;
        if (key == MV_R)
                press->r = 1;
        //looking left, right etc will happen here also
	if (key == ESC)
	{
		press->quit = 1;
	//	exit_clean(err, g);
	}
	return (0);
}
