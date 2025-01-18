/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:09:11 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 11:16:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	floodfill(char **map, int y, int x)
{
	if (map[y][x] == '1' || map[y][x] == 'X' || !map[y][x])
		return ;
	map[y][x] = 'X';
	floodfill(map, y + 1, x);
	floodfill(map, y - 1, x);
	floodfill(map, y, x + 1);
	floodfill(map, y, x - 1);
}

int	checkfill(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == 'X')
			{
				if (mtx[i][j + 1] != '1' && mtx[i][j + 1] != 'X')
					return (0);
				if (mtx[i][j - 1] != '1' && mtx[i][j - 1] != 'X')
					return (0);
				if (mtx[i + 1][j] != '1' && mtx[i + 1][j] != 'X')
					return (0);
				if (mtx[i - 1][j] != '1' && mtx[i - 1][j] != 'X')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	where_is_player(char **mtx, t_player *player)
{
	floodfill(mtx, player->posy, player->posx);
	int i;
	for (i = 0; mtx[i]; i++)
		printf("%s\n", mtx[i]);
	if (!checkfill(mtx))
		return (-69);
	return (1);
}