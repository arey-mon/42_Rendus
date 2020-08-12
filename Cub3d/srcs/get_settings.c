#include "../include/libft.h"
#include "../include/cub3d.h"
#include <stdlib.h>
#include <stdio.h>

// 6 FONCTIONS

void    get_rgb_malloc(t_settings *set)
{
        printf("___ INIT_RGB ___\n");
        if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
                return ;
        if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
                return ;
}

char    *get_texture(char *s)
{
        while (*s == ' ')
                s++;
        printf("texture is : %s\n", ft_strdup(s));
        return (ft_strdup(s));
}

void    get_fc_color(int *rgb, char *s)
{
        printf("___ GET_FC_COLOR\n");
        int i;

        i = 0;
        rgb[i] = ft_atoi(++s);
        i += 1;
        while (*s != ',')
                s++;
        rgb[i] = ft_atoi(++s);
        i += 1;
        while (*s != ',')
                s++;
        rgb[i] = ft_atoi(++s);
        printf("results are rgb[0] == %d _ rgb[0] == %d _ rgb[0] == %d\n", rgb[0], rgb[1], rgb[2]);
}

void    get_res(int *res_x, int *res_y, char *s)
{
        *res_x = ft_atoi(++s);
        while (*s == ' ')
                s++;
        while (ft_isdigit((int)*s))
                s++;
        *res_y = ft_atoi(s);
        printf("outta get_res, results are res_x : %d, res_y : %d\n", *res_x, *res_y);
}

void	get_map(t_settings *set, int fd, char *s)
{
        printf("___ GET_MAP ___\n");
        char    *s2;

        s2 = NULL;
        s = ft_strjoin_free_dest(s, "\n");
        while (get_next_line(fd, &s2))
        {
                s2 = ft_strjoin_free_dest(s2, "\n");
                s = ft_strjoin_free(s, s2);
        }
        if (*s2 != '\n')
                s = ft_strjoin_free(s, s2);
        set->map = ft_split(s, '\n');
        free(s);
	printf("exiting get_map ok\n");
}

int     get_settings(t_settings *set, int fd)
{
        char    *s;

        s = NULL;
        printf("___ GET_SETTINGS ___\n");
        get_rgb_malloc(set);
        s = parse_fd(set, fd, s);
        get_map(set, fd, s);
	close(fd);
        return (0);
}

