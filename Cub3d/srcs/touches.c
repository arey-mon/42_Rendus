#include "../include/cub3d.h"
#include <mlx.h>
#include <X11/Xlib.h>
#include <stdio.h>

// 3 Functions

int	init_moves(t_press press, t_game *g)
{
	printf("___ INIT_MOVES ___\n");
	if (press.f)
	{
		press.f = 1;
		printf("entered press.f\n");
	}	// has to be coded move_f(&g->p, g);	
	if (press.l)
		press.l = 1;
	if (press.r)
		press.r = 1;
	if (press.b)
		press.b = 1;
	if (press.quit)
		exit_clean(0, g);
	return (0);
}

void    init_touches(t_game *g)
{
        g->press.l = 0;
        g->press.r = 0;
        g->press.f = 0;
        g->press.b = 0;
        g->press.quit = 0;
}

int     key_release(int key, t_game *g)
{
        if (key == MV_F)
                g->press.f = 0;
        if (key == MV_B)
                g->press.b = 0;
        if (key == MV_L)
                g->press.l = 0;
        if (key == MV_R)
                g->press.l = 0;
        //looking left, right etc will happen here also
        return (0);
}

int     key_press(int key, t_press *press) 
{
        printf("___ KEY_PRESS ___");
	printf(" you're touching this key : %d\n", key);
	int	err;

        if (key == MV_F)
                press->f = 1;
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
		printf("you pressed ESC, press->quit is : %d\n", press->quit);
	}
	return (0);
}
