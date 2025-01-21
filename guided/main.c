/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:50 by negambar          #+#    #+#             */
/*   Updated: 2025/01/21 11:31:06 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <time.h>

time_t current_time_in_ms() {
    return time(NULL);
}

void	init_game(t_game *game)
{
	char	**mtx;

	init_player(&game->player);
	mtx = NULL;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Cub3D");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	game->image.addr = mlx_get_data_addr(game->img, &game->bpp, \
	&game->size_line, &game->endian);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
}

void draw_wall(t_game *game, int ray, double t_pix, double b_pix, double wall_h)
{
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	t_img	*txt;

	txt = define_side(game);
	tex_x = calc_tex_x(game, txt, game->flag);
	step = (1.0 * (double)64 / (double)wall_h);
	tex_pos = (t_pix - (HEIGHT / 2) + wall_h / 2) * step;
	while (t_pix < b_pix)
	{
		tex_y = calc_tex_y(txt, tex_pos);
		tex_pos += step;
		put_tex_pix(game, ray, t_pix++, get_texture_color(game, tex_x, tex_y));
	}
}

void	render_wall(t_game *game, int ray)
{
	double	wall_h;
	double	b_pix;
	double	t_pix;
	double	proj_dist;

	proj_dist = (WIDTH / 2) / tan(game->player.angle / 2);
	game->distance *= cos(normalize_angle(game->ray_angle - game->player.angle));
	wall_h = (BLOCK / game->distance) * proj_dist;
	b_pix = (HEIGHT / 2) + (wall_h / 2);
	t_pix = (HEIGHT / 2) - (wall_h / 2);
	if (b_pix > HEIGHT)
		b_pix = HEIGHT - 1;
	if (t_pix < 0)
		t_pix = 0;
	draw_wall(game, ray, t_pix, b_pix, wall_h);
}

static void ineedthisfunction(t_game *game)
{
	double	h_inter;
	double	v_inter;

	h_inter = get_h_inter(&game->player, game->map,
		normalize_angle(game->ray_angle));
	v_inter = get_v_inter(&game->player, game->map,
		normalize_angle(game->ray_angle));
	if (v_inter <= h_inter)
		game->distance = v_inter;
	else
	{
		game->distance = h_inter;
		game->flag = 1;
	}
}

static void render_loop(t_game *game, t_player *player)
{
	int		i;

	i = 0;
	while (i < WIDTH)
	{
		game->player.cos = cos(game->ray_angle);
		game->player.sin = sin(game->ray_angle);
		while (!touch(player->x, player->y, game))
		{
			player->x += game->player.cos;
			player->y += game->player.sin;
		}
		ineedthisfunction(game);
		game->distance = fixed_dist(player->x, player->y, player->x, player->y, game);
		extra_funky(i, game);
		game->fov = PI / 3 / WIDTH;
		render_wall(game, i);
		game->ray_angle += (game->player.angle / WIDTH);
		game->ray_angle = normalize_angle(game->ray_angle);
		i++;
	}
}

int	draw_loop(t_game *game)
{
	t_player	*player;
	static long long lasttime = 0;
	long long current;
	long long elapsed;

	current = current_time_in_ms();
	elapsed = current - lasttime;
	if (elapsed < FRAME_TIME_MS)
		usleep((FRAME_TIME_MS - elapsed) * 1000);
	player = &game->player;
	move_player(player, game);
	clear_image(game);
	render_loop(game, player);
	mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
	return (1);
}
