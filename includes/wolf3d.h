/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlobunet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 19:46:56 by vlobunet          #+#    #+#             */
/*   Updated: 2019/10/26 19:46:59 by vlobunet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
# include <unistd.h>
# include <fcntl.h>
# include <time.h>
# include <math.h>
# include <stdlib.h>
# include <signal.h>

# define BLACK "\033[1;30m"
# define RED "\033[1;31m"
# define GREEN "\033[01;38;05;46m"
# define YELLOW "\033[38;05;226m"
# define BLUE "\033[03;38;05;21m"
# define VIOLET "\033[01;38;05;201m"
# define CYAN "\033[1;36m"
# define WHITE "\033[01;38;05;15m"
# define RES "\033[m"

# define UI_B 0x2686D9
# define UI_T 0xAB7C49
# define UI_F 0xB58752
# define BG_CLR 0x353535
# define BG_MAP 0x2F2F2F
# define TX_CLR 0x453A2E
# define MM_CLR 0x3d3d3d

# define WALL_T 0x0D3558
# define WALL_B 0x0B2D4B
# define WALL_N 0x174F80
# define WALL_E 0x1B5C96
# define WALL_S 0x14446e
# define WALL_W 0x804d17
# define AO 0x000000

# define WALL '*'
# define EMPT ' '
# define USER 'X'
# define SECRET_DOOR 'D'
# define DOOR 'd'
# define TARGET 'F'

# define D (double)
# define I (int)
# define FT (float)

# define EER_HEADER "OOops: "
# define ERR_INVALID "Invalid numbers atribytes\n"
# define ERR_EXPLANATION_USE "use: ./wolf3d [name_maps].\n"
# define ERR_FILE "Invalid file descriptor\n"
# define ERR_EXPLANATION_FILE "File not found or unreachable\n"
# define ERR_MAPINVALID "Map is invalid\n"
# define ERR_TEXTURE "Texture file error detected\n"

# define GO_R(m, y, x) ((m[y][x] != '*' && m[y][x] != '#') ? 1 : 0)
# define GO_T(m, y, x) ((m[y][x] != '*' && m[y][x] != '#') ? 1 : 0)
# define GO_L(m, y, x) ((m[y][x] != '*' && m[y][x] != '#') ? 1 : 0)
# define GO_B(m, y, x) ((m[y][x] != '*' && m[y][x] != '#') ? 1 : 0)

# define H			800
# define W			(H * 2)
# define ESC		53

# define SQRT(a, b) (sqrt(1 + (a * a) / (b * b)))
# define CLAMP(x, lw, h)  (((x) > (h)) ? (h) : (((x) < (lw)) ? (lw) : (x)))
# define ROT_SPEED	2
# define MOVE_SPEED 5

# define WIN_W 1280
# define WIN_H 720

typedef struct		s_list
{
	struct s_list	*f;
	struct s_list	*next;
	struct s_list	*prev;
	int				x;
	int				y;
	int				num;
}					t_list;

typedef struct		s_file
{
	char			*str;
	int				fd;
}					t_file;

typedef struct		s_user
{
	double			x;
	double			y;
	int				en;
}					t_user;

typedef struct		s_map
{
	int				col;
	int				row;
	char			**src;
	t_user			user;
}					t_map;

typedef struct		s_vect
{
	double			x;
	double			y;
}					t_vect;

typedef struct		s_vect_i
{
	int				x;
	int				y;
}					t_vect_i;

typedef struct		s_move
{
	int				move_f;
	int				move_b;
	int				move_r;
	int				move_l;
}					t_move;

typedef struct
{
	int				x;
	int				y;
	int				d;
	int				step_x;
	int				step_y;
	int				t_num;
	int				texture_x;
	int				texture_y;
	int				hit;
	int				hit_side;
	int				height;
	int				start;
	int				end;
	int				tx_num;
	int				floor_texx;
	int				floor_texy;
	float			wall_x;
	float			camera;
	float			pwd;
	double			floorxwall;
	double			floorywall;
	double			wall_dst;
	double			player_dst;
	t_vect			pos;
	t_vect			dir;
	t_vect			delta;
	t_vect			side;
	t_vect_i		map;
}					t_render;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				sizeline;
	int				endian;
	t_vect			cam_pl;
	t_vect			cam_vector;
	t_move			move;
	int				shift;
	int				txr;
	float			s_shift;
	double			time;
	double			oldtime;
	double			frametime;
	float			s_move;
	float			s_rot;
	t_render		r;
}					t_mlx;

typedef struct		s_scheme
{
	char			*wall;
	char			*floor;
	char			*ceiling;
}					t_scheme;

typedef struct		s_texture
{
	void			*p;
	char			*img_ptr;
	int				bit_per_pix;
	int				s_line;
	int				endian;
	int				w;
	int				h;
	int				scheme_type;
	t_scheme		*scheme;
}					t_texture;

typedef struct		s_wolf
{
	t_file			fm;
	t_map			map;
	t_list			*path;
	t_mlx			mlx;
	t_texture		*t;
	t_vect			old_position;
	t_vect			posit_pl;
}					t_wolf;

int					g_number;

int					print_error(char *str);
t_wolf				*validation_atributes(char *name, int fd);
char				**map_create(t_wolf *wolf, char **ret, int i, char *line);
void				init_struct(t_wolf *wolf);
int					shortest_path_search(t_wolf *wolf);
t_list				*lst_dell_all(t_list *lst);
void				destroy_struct(t_wolf *wolf);
t_list				*create_tree(t_wolf *wolf, char **map, \
	t_list *lst, int ret);
void				get_texture(t_wolf *m);
void				create_texture(t_wolf *w);
void				go_forward(t_wolf *m);
void				go_backwards(t_wolf *m);
void				rot_left(t_wolf *m);
void				rot_right(t_wolf *m);
void				raycasting(t_wolf *m);
void				floor_render(t_wolf *m);
int					is_movable(double x, double y, t_wolf *m);
void				set_texture(t_wolf *m);
void				wall(t_wolf *m, int x, int n);
int					key_hook_on(int key, t_wolf *m);
int					key_hook_off(int key, t_wolf *m);
int					exit_cl(void *click);
void				ft_freestrarr(char **arr);
void				get_sheme(t_wolf *w);
#endif
