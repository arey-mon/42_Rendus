/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apreymon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 13:10:13 by apreymon          #+#    #+#             */
/*   Updated: 2020/06/11 10:40:16 by apreymon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# ifndef TXT_PATH
#  define TXT_PATH	"./textures/"
# endif

# ifndef SPEED
#  define SPEED	0.1
# endif

# ifndef BLOCK_SIZE
#  define BLOCK_SIZE 1
# endif

# ifndef BLOCK_MAP
#  define BLOCK_MAP 10
# endif

# include "../minilibx-linux-master/mlx.h"
# include "../minilibx_opengl_20191021/mlx.h"
# include "../libft/libft.h"

# define NO_ARG 1
# define INV_EXT 2
# define INV_CUB 3
# define INV_FD 4
# define INV_RES 5
# define INV_PATH 6
# define INV_SP 7
# define INV_CLR 8
# define INV_MAP 9
# define MULT_PLA 10
# define INV_PLA 11
# define ERR_XX 12
# define INV_SYN 13

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

typedef	struct	s_player
{
	float		x;
	float		y;
	int			x_pos;
	int			y_pos;
	double		dir;
	double		fov;
}				t_player;

typedef	struct	s_image
{
	int			x;
	int			y;
	int			size_l;
	int			bpp;
	int			endian;
	float		x_txt;
	float		y_txt;
	void		*ptr;
	int			*d_ptr;
	int			index;
}				t_img;

typedef	struct	s_ray
{
	float		h;
	float		h_x;
	float		h_y;
	float		v;
	float		v_x;
	float		v_y;
	double		d;
	int			side;
}				t_ray;

typedef struct	s_bmp
{
	int			file_size;
	int			pixels_adr;
	int			header_size;
	short		clrs_planes;
	short		bpp;
	int			raw_size;
	int			res;
}				t_bmp;

typedef struct	s_sprite
{
	float		x;
	float		y;
	float		dist;
	double		dir;
}				t_sprite;

typedef	struct	s_settings
{
	int			res_x;
	int			res_y;
	int			map_x;
	int			map_y;
	int			*rgb_f;
	int			*rgb_c;
	int			c_f;
	int			c_c;
	char		*t_n;
	char		*t_e;
	char		*t_s;
	char		*t_w;
	char		*t_sp;
	char		**map;
}				t_settings;

typedef struct	s_input
{
	char		w;
	char		d;
	char		s;
	char		a;
	char		right;
	char		left;
	char		aim;
	char		run;
	int			quit;
	char		shoot;
}				t_input;

typedef struct	s_game
{
	t_settings	set;
	t_player	p;
	t_input		press;
	t_img		img;
	t_img		txt[10];
	t_ray		r;
	float		*buf;
	int			sp_num;
	int			s_dist;
	int			screenshot_off;
	t_sprite	*sp;
	void		*mlx_ptr;
	void		*win_ptr;
}				t_game;

void			get_color(int *set, char *str);
char			*get_text(char *str);
void			get_res(int *res_x, int *res_y, char *str);
void			init_game(t_game *game);
void			init_rgb(t_settings *set);
int				get_height(char **map);
int				get_x_height(t_game *g);
int				get_settings(t_game *g, t_settings *set, int fd);
int				check_ext(char *s);
int				check_ends(char *s);
int				check_map_line(char *str, int *width);
int				check_map_col(char **map, int *width, int x);
int				collision(t_game *g, float x, float y);
int				convert_color(int *rgb);
int				init_moves(t_game *game);
int				in_set(char c, char *charset);
int				key_press(int key, t_input *press);
int				key_release(int key, t_input *press);
int				parse(t_settings *set);
int				check_file(char *str);
int				check_map(char **map, int *map_x, int *map_y, int i);
int				sp_in_fov(t_player p, t_sprite sp);
int				sprite_bite(t_game *g);
int				clean_exit(int error, t_game *game);
int				game_loop(t_game *game);
int				skip_pix(t_img t, int j, int i);
unsigned int	get_txt_color(t_img t, int x, int y);
void			init_game(t_game *g);
void			init_text(t_game *g);
void			init_player(t_game *g);
void			init_keyboard(t_input *press);
void			load_txt(t_img *t, t_game g, char *path);
void			set_hooks(t_game *game);
void			move_front(t_player *p, t_game *g);
void			move_right(t_player *p, t_game *g);
void			move_back(t_player *p, t_game *g);
void			move_left(t_player *p, t_game *g);
void			look_right(t_player *p, char c);
void			look_left(t_player *p, char c);
void			raycast(t_game g);
void			stay_in_circle(double *d);
float			get_wall_h(t_game *g, t_ray *r);
float			get_wall_v(t_game *g, t_ray *r);
float			get_dist(t_game *g, double d, t_ray *r);
float			sprite_dist(t_player *p, t_sprite *sp);
t_img			select_text(t_game g);
t_sprite		*sort_sprite(t_sprite *sp, int count);
void			init_sprite(t_game *g, t_settings s);
void			draw_column(t_game g, double d, int x);
void			draw_window(t_game *g);
void			draw_ray(t_img i, t_player p, double dir, int d);
void			draw_square(t_img i, int c, int x, int y);
void			draw_line(t_img *i, int x, int y, int dist);
void			draw_map(t_game *g);
double			sprite_dir(t_player p, t_sprite sp);
void			draw_sprite(t_game *g);
void			screenshot(t_img i, t_game g);
void			set_res(t_game *g, int x, int y);

#endif
