/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 18:04:29 by negambar          #+#    #+#             */
/*   Updated: 2025/01/21 11:27:17 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	*find_img(t_sp *t, char c)
{
	if (c == 'w')
		return (t->sw);
	if (c == 'e')
		return (t->se);
	if (c == 'n')
		return (t->sn);
	if (c == 's')
		return (t->sps);
	return (NULL);
}

void	put_tex_pix(t_game *game, int x, int y, int color)
{
	char	*pixel;
	printf("%d", color);
	pixel = (game->image.addr + ((y * game->size_line) + x * (game->bpp / 8)));
	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	*(int *)pixel = color;
}

void	extra_funky(int i, t_game *game)
{
	float	height;
	int		start_y;
	int		end;
	double	step;

	(void)i;
	height = (BLOCK / game->distance) * (WIDTH / 2);
	start_y = (HEIGHT - height) / 2;
	end = start_y + height;

	int tmp_x, tmp_y;
	double tex_pos;

	tmp_x = 255;
	step = (1.0 * (double)64 / (double)HEIGHT);
	tex_pos = (start_y - (HEIGHT / 2) + height / 2) * step;
	tmp_y = tex_pos - floor(tex_pos);
	while (start_y < end)
	{
		put_tex_pix(game, tmp_y, tmp_x, 255);
		start_y++;
	}
}

void	put_pixel(int x, int y, int color, t_game *game)
{
	int	index;

	if (x >= WIDTH || y >= HEIGHT || x < 0 || y < 0)
		return ;
	index = y * game->size_line + x * game->bpp / 8;
	game->image.addr[index] = color & 0xFF;
	game->image.addr[index + 1] = (color >> 8) & 0xFF;
	game->image.addr[index + 2] = (color >> 16) & 0xFF;
}

void	updownleftright(t_player *player, t_game *game)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	if (player->keyup)
		move_up(player, x, y, game);
	if (player->keydown)
		move_down(player, x, y, game);
	if (player->keyleft)
		move_left(player, x, y, game);
	if (player->keyright)
		move_right(player, x, y, game);
}
