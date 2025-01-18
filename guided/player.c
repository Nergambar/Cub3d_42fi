/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:01:19 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 11:16:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

void	init_player(t_player *player)
{
	player->x = player->posx * 64;
	player->y = player->posy * 64;
	player->angle = PI / 2;
	player->keyup = false;
	player->keydown = false;
	player->keyleft = false;
	player->keyright = false;
	player->left_rotate = false;
	player->right_rotate = false;
}

static void	rot_player(t_player *player)
{
	float	angle_speed;

	angle_speed = 0.03;
	if (player->left_rotate)
		player->angle -= angle_speed;
	if (player->right_rotate)
		player->angle += angle_speed;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
}

void	move_player(t_player *player, t_game *game)
{
	rot_player(player);
	updownleftright(player, game);
}
