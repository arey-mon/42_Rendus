#ifndef CUB3D_H
# define CUB3D_H

#ifndef TEXTURES_PATH
# define TEXTURES_PATH "./textures/"
#endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE   100
# endif

typedef struct	s_settings
{
	int	res_x;
	int	res_y;
	int	*rgb_c;
	int	*rgb_f;
	char	**map;
	char	*t_n;
	char	*t_w;
	char	*t_s;
	char	*t_e;
	char	*t_sp;
}		t_settings;

typedef struct	s_img
{
	int	x;
	int	y;
	void	*tmp;
}		t_img;

typedef	struct	s_player
{
	int	x_pos;
	int	y_pos;
}		t_player;

typedef	struct	s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_img		txt[10];
	t_settings	set;
	t_player	p;
}		t_game;

int	open_fd(char *str);
int	check_ext(char *s);
int	check_rgb(int *f, int *c);
char	**err_msg();
int	exit_clean(int err, t_game *g);
void    get_map(t_settings *set, int fd, char *s);
void	get_res(int *res_x, int *res_y, char *s);
char	*get_texture(char *s);
void	get_fc_color(int *rgb, char *s);
int	get_settings(t_settings *set, int fd);
void	get_rgb_malloc(t_settings *set);
char	*parse_fd(t_settings *set, int fd, char *s);
int	parse_fd_check(t_settings *set);

# define INV_FD 1
# define INV_RES 2
# define INV_EXT 3
# define INV_RGB 4

# define MV_F 122
# define MV_B 115
# define MV_L 113
# define MV_R 100
# define LOOK_L 65361
# define LOOK_R 65363
# define RUN 65505
# define AIM 32
# define SHOOT 65362
# define ESC 65307
# define RUN 65505

#endif
