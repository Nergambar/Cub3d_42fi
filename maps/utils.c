/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:01:47 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 11:16:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int check_for_player(char **mtx, t_player *player)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(mtx[j])
	{
		i = 0;
		while (mtx[j][i])
		{
			if (mtx[j][i] == 'W')
			{
				player->posx = i;
				player->posy = j;
				// printf("posx:%d\nposy:%d", player->posx, player->posy);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

int	check_map(char **mtx, t_player *player)
{
	if (!check_for_player(mtx, player))
		return (-99999);
	if (where_is_player(mtx, player) != 1)
	{
		printf("mah");
		return(-9999);
	}
	// if (!wall_maria(mtx, player))
	// 	return(-420);
	return (1);
}