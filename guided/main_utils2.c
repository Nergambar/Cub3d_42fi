/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:40:33 by negambar          #+#    #+#             */
/*   Updated: 2025/01/21 11:42:32 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	get_texture_color(t_game *txt, int x, int y)
{
	char	*pixel;
	int		color;

	pixel = txt->data + ((y * txt->size_line) + (x + txt->bpp / 8));
	color = *(int *)pixel;
	return (color);
}

int	wall_hit(float x, float y, t_map *map)
{
	int	x_m;
	int	y_m;

	if (x < 0 || y < 0)
		return (0);
	x_m = floor (x / BLOCK);
	y_m = floor (y / BLOCK);
	if ((y_m >= map->h_map || x_m >= map->w_map || y_m <= 0 || x_m <= 0))
		return (0);
	if (map->map[y_m][x_m] == '1')
		return (0);
	return (1);
}

float	get_h_inter(t_player *player, char **map, float angle)
{
	float	h_x;
	float	h_y;
	float	x_step;
	float	y_step;
	int		pixel;

	y_step = BLOCK;
	x_step = BLOCK / tan(angle);
	h_y = floor(player->y / BLOCK) * BLOCK;
	pixel = inter_check(angle, &h_y, &y_step, 1);
	h_x = player->x + (h_y - player->y) / tan(angle);
	if ((unit_circle(angle, 'y') && x_step > 0)
		|| (!unit_circle(angle, 'y') && x_step < 0))
		x_step *= -1;
	while (wall_hit(h_x, h_y - pixel, map))
	{
		h_x += x_step;
		h_y += y_step;
	}
	return (sqrt(pow(h_x - player->x, 2) + pow(h_y - player->y, 2)));
}

float	get_v_inter(t_player *player, char **map, float angl)
{
	float	v_x;
	float	v_y;
	float	x_step;
	float	y_step;
	int		pixel;

	x_step = BLOCK;
	y_step = BLOCK * tan(angl);
	v_x = floor(player->x / BLOCK) * BLOCK;
	pixel = inter_check(angl, &v_x, &x_step, 0);
	v_y = player->y + (v_x - player->x) * tan(angl);
	if ((unit_circle(angl, 'x') && y_step < 0)
		|| (!unit_circle(angl, 'x') && y_step > 0))
		y_step *= -1;
	while (wall_hit(v_x - pixel, v_y, map))
	{
		v_x += x_step;
		v_y += y_step;
	}
	return (sqrt(pow(v_x - player->x, 2) + pow(v_y - player->y, 2)));
}

int	key_press(int keycode, t_game *game)
{
	t_player *player;

	player = &game->player;
	if (keycode == W)
		player->keyup = true;
	if (keycode == S)
		player->keydown = true;
	if (keycode == A)
		player->keyleft = true;
	if (keycode == D)
		player->keyright = true;
	if (keycode == LEFT)
		player->left_rotate = true;
	if (keycode == RIGHT)
		player->right_rotate = true;
	if (keycode == ESC)
		exit_hook(game);
	return (0);
}

int	key_release(int keycode, t_player *player)
{
	if (keycode == W)
		player->keyup = false;
	if (keycode == S)
		player->keydown = false;
	if (keycode == A)
		player->keyleft = false;
	if (keycode == D)
		player->keyright = false;
	if (keycode == LEFT)
		player->left_rotate = false;
	if (keycode == RIGHT)
		player->right_rotate = false;
	return (0);
}
