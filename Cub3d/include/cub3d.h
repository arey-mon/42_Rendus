#ifndef CUBE_3D_H
# define CUBE_3D_H

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
	int	map_x;
	int	map_y;
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
	float	x_texture;
	float	y_texture;
	void	*ptr;
}		t_img;

typedef	struct	s_player
{
	double	fov;
	double	dir;
	int	x_pos;
	int	y_pos;
	float	x;
	float	y;
}		t_player;

typedef	struct	s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
	t_img		txt[10];
	t_settings	set;
	t_player	p;
}		t_game;

int		check_ext(char *str);
int		clean_exit(int err, t_game *g);
char		**init_msg(void);
void		get_settings(t_settings *set, int fd);
void		get_map(t_settings *set, int fd, char *str);
void		init_fc(t_settings *set);


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

# define NO_MAP 1
# define WRONG_EXT 2
# define INV_CUB 3
# define INV_RES 4
# define INV_PATH 5
# define INV_SP 6
# define NO_UTI 7
# define INV_CLR 8
# define INV_MAP 9
# define NOT_CLS 10
# define NO_PLA 11
# define MULT_PLA 12

#endif
