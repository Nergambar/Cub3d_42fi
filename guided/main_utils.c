/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:19:30 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 12:27:18 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	calc_wall_px_hit(t_game *game, int flag)
{
	double	wall_px;

	if (flag == 0)
		wall_px = game->player.posy + game->distance
			* game->player.y;
	else
		wall_px = game->player.posx + game->distance
			* game->player.x;
	return (wall_px);
}

t_img	*define_side(t_game *game)
{
	t_img	*txt;

	if (game->flag == 0)
	{
		if (game->ray_angle > PI / 2 && game->ray_angle < 3 * (PI / 2))
			txt = &game->t.sw;
		else
			txt = &game->t.se;
	}
	else
	{
		if (game->ray_angle > 0 && game->ray_angle < PI)
			txt = &game->t.sps;
		else
			txt = &game->t.sn;
	}
	return (txt);
}
int	int_imax(int n1, int n2)
{
	if (n1 >= n2)
		return (n1);
	return (n2);
}

int calc_tex_x(t_game *game, t_img *txt, int flag)
{
	int		tex;
	double	hit;

	if (!txt)
		return (0);
	if (isinf(game->player.x) || isinf(game->player.y))
		exit(1);
	hit = calc_wall_px_hit(game, flag) / 64;
	hit -= floor(hit);
	tex = (int)((hit) * 64);
	if (txt && txt->width > 0 && tex >= txt->width)
		tex = txt->width - 1;
	tex = int_imax(0, tex);
	return (tex);
}

int	calc_tex_y(t_img *texture, double tex_pos)
{
	const t_img	*tex;
	int			text_y;

	tex = texture;
	if (!texture)
		return (0);
	text_y = tex_pos * tex->height / 64;
	if (tex && tex->height > 0 && text_y >= tex->height)
		text_y = tex->height - 1;
	text_y = int_imax(0, text_y);
	return (text_y);
}