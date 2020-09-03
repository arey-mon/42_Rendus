#include "../include/cub3d.h"
#include <math.h>
#include <stdio.h>

// 3 Functions

void	move_front(t_player *p, t_game *g)
{
	printf("m o v e       f r o n t \n");
        float x;
        float y;

        x = p->x + cos(p->dir) * SPEED;
        y = p->y + sin(p->dir) * SPEED;
       
       printf("x must change : %f\n", x);	
	/*
	 * if (check_w(g, x, p->y) != 1)
                p->x = x;
        if (check_w(g, p->x, y) != 1)
                p->y = y;
	*/
}

int	init_moves(t_press press, t_game *g)
{
	printf("___ INIT_MOVES ___\n");
	if (press.f)
		move_front(&g->p, g);
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
