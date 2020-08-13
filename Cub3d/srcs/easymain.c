#include <fcntl.h>
#include "mlx.h"
#include "../include/libft.h"
#include <stdlib.h>
#include <stdio.h>

//#ifndef CUB3D_H 
//# define CUB3D_H

# ifndef CHARSET
#  define CHARSET       "012NESW"
# endif

typedef struct  s_player
{
        float   x;
        float   y;
}		t_player;


typedef struct	s_settings
{
	int	res_x;
	int	res_y;
        char    *t_n;
	char    *t_e;
	char    *t_s;
	char    *t_w;
	char    *t_sp;
	int	*rgb_f;
        int	*rgb_c;
        int	c_f;
        int	c_c;
	char	**map;
        int             map_x;
        int             map_y;
}		t_settings;

typedef struct		s_img
{
	int             size_l;
        int             bpp;
        int             endian;
	void		*ptr;
	int		*data;
	int		x;
	int		y;
}			t_img;

typedef struct		s_game
{
        t_player        p;
	t_settings	set;
	t_img		img;
	t_img           txt[10];
	void		*mlx;
	void		*win;
}			t_game;

int		check_colors(int *x, int *y);
int		check_res(t_settings *set);
int		check_fd(char *s);
int		check_ext(char *str);
static int      check_ends(char *s);
int                     check_map(char **map, int *map_x, int *map_y);
static int      check_map_col(char **map, int *width, int x);
static int      check_map_line(char *str, int *width);
int             convert_color(int *rgb);
int		exit_clean(int err, t_game *g);
char		*fill_fields(t_settings *set, int fd, char *str);
void		get_color(int *set, char *str);
static void     get_map(t_settings *set, int fd, char *str);
char		*get_txt(char *str);
void		get_res(int *res_x, int *res_y, char *str);
void		get_settings(t_settings *set, int fd);
int                     in_set(char c, char *charset);
void		init_rgb(t_settings *set);
void		init_game(t_game *g);
static void	init_textures(t_game *g);
void		init_mlx(t_img *i, t_game *g);
void		load_txt(t_img *i, t_game g, char *path);
char		**msg_err(void);
int		parse_fd(t_settings *set);
void		set_res(t_game *g, int x, int y);
void    touch_loop(t_game *g);
int     game_loop(t_game *g);
void    draw_window(t_game *g);
static void     play_game(t_game *g);
void    raycast(t_game g);


# define ARG 0
# define EXT 1
# define INV_COL 2
# define INV_FD 3
# define INV_RES 4
# define INV_MAP 5

// #endif
//////////////////////////////////:

int                     in_set(char c, char *charset)
{
        while (*charset) 
                if (c == *(charset++))
                        return (1);
        return (0);
}

static int      check_ends(char *s)
{
        while (*s)
        {
                while (*s == ' ')
                        s++;
                if (*s != '1' && *s != '\0')
                        return (1);
                while (*s == '1')
                        s++;
                if (*s != ' ' && *s != '\0')
                        return (1);
        }
        return (0);
}

static int      check_map_line(char *str, int *width)
{
        int i;

        i = 0;
        while (str[i])
        {
                while (str[i] == ' ')
                        i++;
                if (str[i] != '1' && str[i] != '\0')
                        return (1);
                while (str[i] && in_set(str[i], CHARSET))
                        i++;
                if (str[i] != ' ' && str[i] != '\0')
                {
                        return (1);
                }
                else if (str[i] == ' ' && str[i - 1] != '1')
                        return (1);
        }
        *width = i;
        return (0);
}

static int      check_map_col(char **map, int *width, int x)
{
        int i;

        i = 0;
        while (map[i])
        {
                while (x > width[i] - 1)
                        i++;
                while (map[i] && x < width[i] && map[i][x] == ' ')
                        i++;
                if (map[i] && map[i][x] && map[i][x] != '1')
                        return (1);
                while (map[i] && in_set(map[i][x], CHARSET))
                        i++;
                if (map[i] && (map[i][x] != ' ' && map[i][x]))
                        return (1);
                else if (map[i] && (map[i][x] == ' ' && map[i - 1][x] != '1'))
                        return (1);
        }
        return (0);
}

int                     check_map(char **map, int *map_x, int *map_y)
{
	printf("___ CHECK_MAP ___\n");
        int             i;
        int             *tmp;

        i = 0;
        *map_x = 0;
        *map_y = 0;
        while (map[*map_y])
                (*map_y)++;
        if (check_ends(map[0]) || check_ends(map[*map_y - 1]))
                return (INV_MAP);
        if (!(tmp = (int *)malloc(sizeof(int) * *map_y)))
                return (INV_MAP);
        while (i < *map_y)
        {
                if (check_map_line(map[i], &tmp[i]))
                        return (INV_MAP);
                if (tmp[i++] > *map_x)
                        *map_x = tmp[i - 1];
        }
        i = 0;
        while (i < *map_x)
                if (check_map_col(map, tmp, i++))
                        return (INV_MAP);
        free(tmp);
        return (0);
}

int             convert_color(int *rgb)
{
	printf("___ CONVERT_COLORS ___\n");
        return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int	check_ext(char *str)
{
	printf("___ CHECK_EXT ___\n");
	char	*c;

	c = ft_strrchr(str, '\0');
	c -= 1;
	while (*c == ' ')
		c--;
	if (*c == 'b' && *(c - 1) == 'u' && *(c - 2) == 'c' && *(c - 3) == '.')
	{
		if (check_fd(str) > 0)
			return (INV_FD);
		return (0);
	}
	return (EXT);
}

char	**msg_err(void)
{
	char	**msg;

	if (!(msg = ft_calloc(sizeof(char *), 14)))
		return (NULL);
	msg[ARG] = "Missing Arguments";
	msg[EXT] = "Wrong Extension";
	msg[INV_MAP] = "Map is invalid";
	msg[INV_FD] = "File is invalid";
	return (msg);
}

void	set_res(t_game *g, int x, int y)
{
	ft_putstr_fd(">>> went into set_res\n", 1);
	printf("x is : %d __ res_x is : %d\ny is : %d __ res_y is : %d\n", x, g->set.res_x, y, g->set.res_y);
	
	if (g->set.res_x > x)
		g->set.res_x = x;
	else
		x = g->set.res_x;
	if (g->set.res_y > y)
		g->set.res_y = y;
	else
		y = g->set.res_y;
	printf("x is : %d __ res_x is : %d\ny is : %d __ res_y is : %d\n", x, g->set.res_x, y, g->set.res_y);
	ft_putstr_fd(">>> went out of set_res\n", 1);
}

int	exit_clean(int err, t_game *g)
{
	char	**msg;

	ft_putstr_fd("Error\n", 1);
	msg = msg_err();
	ft_putstr_fd(msg[err], 1);
	exit(0);
	return (0);
}

void		load_txt(t_img *i, t_game g, char *path)
{
	int	*p;

        i->ptr = mlx_xpm_file_to_image(g.mlx, path, &i->x, &i->y);
        p = (int *)mlx_get_data_addr(i->ptr, &i->bpp, &i->size_l, &i->endian);
//      i->d_ptr = p;
        i->size_l /= 4;
}

static void     init_textures(t_game *g)
{
	ft_putstr_fd(">>> went into init_textures", 1);
        load_txt(&(g->txt[0]), *g, g->set.t_n);
        load_txt(&(g->txt[1]), *g, g->set.t_e);
        load_txt(&(g->txt[2]), *g, g->set.t_s);
        load_txt(&(g->txt[3]), *g, g->set.t_w);
        load_txt(&(g->txt[4]), *g, g->set.t_sp);
	ft_putstr_fd(">>> went out of init_textures", 1);
}

void	draw_window(t_game *g)
{
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
}

void		raycast(t_game g)
{
	printf("entering raycast function\n");
}

static void     play_game(t_game *g)
{
	raycast(*g);
}

int	game_loop(t_game *g)
{
	//if press.pause >>> exit
	play_game(g);
	draw_window(g); // I don't see the use here
	return (0);
}

void	touch_loop(t_game *g)
{
	printf("___ TOUCH_LOOP\n");
	// mlx_hook for touches, press, release and escape game
	mlx_loop_hook(g->mlx, &game_loop, g);
}

void	init_mlx(t_img *img, t_game *g)
{
	ft_putstr_fd(">>> went into init_mlx\n", 1);
	int	x;
	int	y;

	g->mlx = mlx_init();
	mlx_get_screen_size(g->mlx, &x, &y);
	printf("before set_res, x is : %d __ y s %d\n", x, y);
	set_res(g, x, y);
	g->win = mlx_new_window(g->mlx, x, y, "Cub3D");
	img->ptr = mlx_new_image(g->mlx, x, y);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->bpp, &img->size_l, &img->endian);
	touch_loop(g);
	ft_putstr_fd(">>> went out of init_mlx\n", 1);
}

void	init_game(t_game *g)
{
	void	*win;

	ft_putstr_fd(">>> went into init_game\n", 1);
	init_mlx(&(g->img), g);
//	init_textures(g);
	
}

void	init_rgb(t_settings *set)
{
	ft_putstr_fd("___ into init_rgb\n", 1);
        if (!(set->rgb_f = (int*)malloc(sizeof(int) * 3)))
                return ;
        if (!(set->rgb_c = (int*)malloc(sizeof(int) * 3)))
                return ;
	ft_putstr_fd(">>> went out of init_rgb\n", 1);
}

void            get_color(int *set, char *str)
{
	printf("___ into get_color\n");
        set[0] = ft_atoi(++str);
        while (*str != ',')
        {
                if (!ft_isdigit(*str) && *str != ' ')
                        set[0] = -1;
                str++;
        }
        set[1] = ft_atoi(++str);
        while (*str != ',')
        {
                if (!ft_isdigit(*str) && *str != ' ')
                        set[1] = -1;
                str++;
        }
        set[2] = ft_atoi(++str);
}

char            *get_txt(char *str)
{
	printf("___ into get_txt\n");
	while (*str == ' ')
                str++;
        return (ft_strdup(str));
}

void    get_res(int *res_x, int *res_y, char *str)
{
	printf("___ into get_res\n");
        *res_x = ft_atoi(str++);
        while (*str == ' ')
                str++;
        while (*str >= '0' && *str <= '9')
                str++;
        *res_y = ft_atoi(str);
}

char	*fill_fields(t_settings *set, int fd, char *str)
{
	printf("___ FILL_FIELDS ___\n");
        while (get_next_line(fd, &str))
        {
                if (*str == '1' || *str == '0')
                        return (str);
                if (*str == 'R')
                        get_res(&set->res_x, &set->res_y, str);
                else if (*str == 'N')
                        set->t_n = get_txt(str + 2);
                else if (*str == 'E')
                        set->t_e = get_txt(str + 2);
                else if (*str == 'W')
                        set->t_w = get_txt(str + 2);
                else if (*str == 'S' && *(str + 1) == 'O')
                        set->t_s = get_txt(str + 2);
		else if (*str == 'C')
			get_color(set->rgb_c, str);
		else if (*str == 'F')
			get_color(set->rgb_f, str);
	}
	free(str);
	return (NULL);
}

static void     get_map(t_settings *set, int fd, char *str)
{
        printf("___ GET_MAP ___\n");
        char    *s2;

        s2 = NULL;
        str = ft_strjoin_free_dest(str, "\n");
        while (get_next_line(fd, &s2))
        {
                s2 = ft_strjoin_free_dest(s2, "\n");
                str = ft_strjoin_free(str, s2);
        }
        if (*s2 != '\n')
                str = ft_strjoin_free(str, s2);
        set->map = ft_split(str, '\n');
        free(str);
}

void	get_settings(t_settings *set, int fd)
{
	printf("___ GET_SETTINGS ___\n");
	char	*str;

	str = NULL;
	init_rgb(set);
	str = fill_fields(set, fd, str);
	get_map(set, fd, str);
	close(fd);
}

int	check_colors(int *x, int *y)
{
	printf("___ CHECK_COLORS ___\n");
	if (x[0] < 0 || x[0] > 255 || x[1] < 0 || x[1] > 255 || x[2] < 0 || x[2] > 255)	
		return (1);
	if (y[0] < 0 || y[0] > 255 || y[1] < 0 || y[1] > 255 || y[2] < 0 || y[2] > 255)
	        return (1);
	return (0);
}

int	check_res(t_settings *set)
{
	printf("___ CHECK_RES ___\n");
	if (set->res_x <= 0 || set->res_y <= 0)
		return (1);
        return (0);
}

int	check_fd(char *s)
{
	printf("___ CHECK_FD ___\n");
	int	fd;
	int	ret;
	char	s2[10];

	fd = open(s, O_RDONLY);
	ret = read(fd, &s2, 10);
	close(fd);
	printf("ret is %d\n", ret);
	if (ret <= 0)
		return (INV_FD);
	return (0);
}

int	parse_fd(t_settings *set)
{
	printf("___ PARSE_FD ___\n");
	if (check_fd(set->t_n) > 0 || check_fd(set->t_e) > 0 || check_fd(set->t_w) > 0 || check_fd(set->t_s) > 0)
		return (INV_FD);
	// sprites will be needed here also
	if (check_res(set))
		return (INV_RES);
	if (check_colors(set->rgb_f, set->rgb_c) > 0)
	{
		printf("check colors is above 0\n");
		free(set->rgb_c);
		free(set->rgb_f);
		return (INV_COL);
	}
	set->c_c = convert_color(set->rgb_c);
	set->c_f = convert_color(set->rgb_f);
	free(set->rgb_c);
	free(set->rgb_f);
	ft_putstr_fd(">>> went out of parse_fd\n", 1);
	return (check_map(set->map, &set->map_x, &set->map_y));
}

int	main(int ac, char **av)
{
	printf("___ MAIN ___\n");
	t_game	g;
	int	err;

	if ((ac < 2) ||((err = check_ext(av[1]))))
		exit_clean(err, &g);
	get_settings(&g.set, open(av[1], O_RDONLY));
	parse_fd(&g.set);
	printf("err is = %d\n", err);
//	(err == 0) ? init_game(&g) : exit_clean(err, &g);	
	g.set.map[(int)g.p.y][(int)g.p.x] = '0';
	g.img.x = g.set.res_x;
        g.img.y = g.set.res_y;
	mlx_loop(g.mlx);
	return (0);
}
