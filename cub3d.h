/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:47:00 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 13:16:39 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <fcntl.h>
#include <stdbool.h>
#include <limits.h>
#include <time.h>
#include "./minilibx-linux/mlx.h"
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

# define HEIGHT 900
# define WIDTH 1600
# define BLOCK 64
# define W 119
# define A 97
# define S 115
# define D 100
# define ESC 65307
# define LEFT 65361
# define RIGHT 65363
# define PI 3.14159265359
# define DEBUG 0
# define TARGET_FPS 50
# define FRAME_TIME_MS (1000 / TARGET_FPS)

typedef struct s_player
{
	float	x;
	float	y;
	double	cos;
	double	sin;
	int		posx;
	int		posy;
	float	angle;
	bool	keyup;
	bool	keydown;
	bool	keyleft;
	bool	keyright;
	bool	left_rotate;
	bool	right_rotate;
}	t_player;

typedef	struct s_ray
{
	char	tile;
	float	delta_x;
	float	delta_y;
	float	angle;
	float	fix_dist;
}	t_ray;

typedef struct s_textures
{
	int		f;
	int		c;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_textures;

typedef struct s_sprites
{
	int		x;
	int		y;
	void	*sn;
	void	*sps;
	void	*sw;
	void	*se;
}	t_sp;

typedef struct s_details
{
	void	*mlx;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**mf;
	char	**mc;
}	t_details;

typedef struct s_img
{
	void	*mlx_img;
	void	*img;
	
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		height;
	int		width;
}	t_img;

typedef struct s_tex
{
	t_img	imgg;
	int		*text_value;
}	t_tex;

typedef struct s_game
{
	void				*mlx;
	double				distance;
	void				*win;
	int					*img;
	char				**map;
	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	double				ray_angle;
	int					flag;
	double				fov;
	struct s_tex		txt;
	struct s_img		image;
	struct s_details	dets;
	struct s_sprites	t;
	struct s_player		player;
}	t_game;

double	calc_wall_px_hit(t_game *game, int flag);
t_img	*define_side(t_game *game);
int		calc_tex_x(t_game *game, t_img *txt, int flag);
int		calc_tex_y(t_img *texture, double tex_pos);
void	put_tex_pix(t_game *game, int x, int y, int color);
int		get_texture_color(t_img *txt, int x, int y);
float	get_h_inter(t_player *player, char **map, float angle);
float	get_v_inter(t_player *player, char **map, float angle);
int	key_press(int keycode, t_game *game);
int	key_release(int keycode, t_player *player);

float	fixed_dist(float x1, float y1, float x2, float y2, t_game *game);
t_ray	*ray_lstnew(float x, float y, float angle, float fix_dist);
void	init_player(t_player *player);
void	extra_funky(int i, t_game *game);
int		key_press(int key, t_game *game);
int		key_released(int key, t_player *player);
void	move_player(t_player *player, t_game *game);
int		ft_close(t_game *loop);
void	put_pixel(int x, int y, int color, t_game *game);
void	clear_image(t_game *game);
void	draw_map(t_game *game);
float	distance(float x, float y);
float	normalize_angle(float angle);
bool	touch(float px, float py, t_game *game);
void	updownleftright(t_player *player, t_game *game);
void	init_game(t_game *game);
int		draw_loop(t_game *game);

void	move_up(t_player *player, int x, int y, t_game *game);
void	move_down(t_player *player, int x, int y, t_game *game);
void	move_left(t_player *player, int x, int y, t_game *game);
void	move_right(t_player *player, int x, int y, t_game *game);

int		where_is_player(char **mtx, t_player *player);
void	init_attrs(t_game *game);
char	**mtxdup(char **av, int fd);
char	*get_the_line(int fd);
int		ft_strrchr2(char *s, char *c);
size_t	get_max_width(char *av);
size_t	get_height(char *av);
int		mtx_trim(char **mtx);
char	**map_mtx(char **mtx, char *av, t_game *game);
bool	empy_line(char *line);
void	freemtx(char **mtx);
int		check_extras(char **mtx, t_game *game, int trimmed);
void	freeatts(t_details *dets);
int		set_colors(t_textures *txt, t_details *dets);
int		check_wall_available(t_details *details, t_sp *sprites);
void	closeall(char **mtx, t_details dets);
void	printfchecks(t_details dets, t_textures txt);
char	**initial_checks(char **av, t_game *game);
char	which_wall(float x, float y);
int		check_map(char **mtx, t_player *player);
char	**utils(char **av);

#endif