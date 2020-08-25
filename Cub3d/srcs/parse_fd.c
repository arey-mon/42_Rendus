#include "../include/libft.h"
#include "../include/cub3d.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

// 6 functions

int	convert_rgb(int *rgb)
{
	printf(">>> CONVERT_RGB <<<\n");
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int     check_rgb(int *f, int *c)
{
        if (c[0] < 0 || c[0] > 255 || c[1] < 0 || c[1] > 255 ||
                        c[2] < 0 || c[2] > 255)
                return (1);
        if (f[0] < 0 || f[0] > 255 || f[1] < 0 || f[1] > 255 ||
                        f[2] < 0 || f[2] > 255)
                return (1);
        return (0);
}

int     check_ext(char *s)
{
        int i;

        i = 0;
        while (s[i] != '\0')
                i++;
        i -= 1;
        while (s[i] == ' ')
                i--;
        if (*s != 'b' && s[i - 1] != 'u' && s[i - 2] != 'c' && s[i - 3] != '.')
                return (INV_EXT);
        printf("Extension seems right\n");
        return (0);
}

int     open_fd(char *str)
{
        printf("___ CHECK_FD ___\n");
        int     fd;
        int     ret;
        char    s[10];

        fd = open(str, O_RDONLY);
        ret = read(fd, &s, 10);
        close(fd);
        if (ret <= 0)
                return (INV_FD);
        printf("ret is : %d, all went well\n", ret);
        return (0);
}

int     parse_fd_check(t_settings *set)
{
        if (set->res_x <= 0 || set->res_y <= 0)
                return (INV_RES);
printf("set->t_n is : %s\n", set->t_n);
	if (open_fd(set->t_n) || open_fd(set->t_w) || open_fd(set->t_s)                 || open_fd(set->t_sp) || open_fd(set->t_w))
		return (INV_FD); 
        if (check_rgb(set->rgb_f, set->rgb_c))
	{
		free(set->rgb_f);
		free(set->rgb_c);
		return (INV_RGB);
	}
	set->c_c = convert_rgb(set->rgb_c);
	set->c_f = convert_rgb(set->rgb_f);
	return (check_map(set->map, &set->map_x, &set->map_y));
}

char    *parse_fd(t_settings *set, int fd, char *s)
{
        printf("___ INTO FILL_MAP ___\n");
        while (get_next_line(fd, &s))
        {
                if (*s == '1' || *s == '0')
                        return (s);
                if (*s == 'R')
                        get_res(&set->res_x, &set->res_y, s);
                else if (*s == 'N')
                        set->t_n = get_texture(s + 2);
                else if (*s == 'E')
                        set->t_e = get_texture(s + 2);
                else if (*s == 'S' && *(s + 1) == 'O')
                        set->t_s = get_texture(s + 2);
                else if (*s == 'W')
                        set->t_w = get_texture(s + 2);
                else if (*s == 'S')
                        set->t_sp = get_texture(s + 1);
                else if (*s == 'F')
                        get_fc_color(set->rgb_f, s);
                else if (*s == 'C')
                        get_fc_color(set->rgb_c, s);
                free(s);
        }
        return (NULL);
}
