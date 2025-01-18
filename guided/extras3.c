/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extras3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 12:55:18 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 12:55:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

bool	touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (!game || !game->map)
		exit(0);
	if (game->map[y][x] == '1')
		return (true);
	return (false);
}

char	which_wall(float x, float y)
{
	if (x - (int)x < 0.0000001)
		return ('w');
	else if (y - (int)y < 0.0000001)
		return ('n');
	else if (x - (int)x > 0.9999999)
		return ('e');
	else 
		return ('s');
}