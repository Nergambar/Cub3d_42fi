/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:15:36 by negambar          #+#    #+#             */
/*   Updated: 2024/12/16 12:08:12 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_player(t_player **player, t_game *game, int x, int y)
{
	char	**mtx;

	mtx = game->map;
	if (mtx[y / 64][x / 64] != '1')
	{
		(*player)->x = x;
		(*player)->y = y;
	}
}

void	move_up(t_player *player, int x, int y, t_game *game)
{
	int		speed;
	float	sin_angle;
	float	cos_angle;

	speed = 3;
	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	x = player->x + cos_angle * speed;
	y = player->y + sin_angle * speed;
	check_player(&player, game, x, y);
}

void	move_down(t_player *player, int x, int y, t_game *game)
{
	int		speed;
	float	sin_angle;
	float	cos_angle;

	speed = 3;
	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	x = player->x - cos_angle * speed;
	y = player->y - sin_angle * speed;
	check_player(&player, game, x, y);
}

void	move_left(t_player *player, int x, int y, t_game *game)
{
	int		speed;
	float	sin_angle;
	float	cos_angle;

	speed = 3;
	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	x = player->x + sin_angle * speed;
	y = player->y - cos_angle * speed;
	check_player(&player, game, x, y);
}

void	move_right(t_player *player, int x, int y, t_game *game)
{
	int		speed;
	float	sin_angle;
	float	cos_angle;

	speed = 3;
	sin_angle = sin(player->angle);
	cos_angle = cos(player->angle);
	x = player->x - sin_angle * speed;
	y = player->y + cos_angle * speed;
	check_player(&player, game, x, y);
}
