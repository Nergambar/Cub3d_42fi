/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:46:02 by negambar          #+#    #+#             */
/*   Updated: 2025/01/21 11:43:05 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall_available(t_details *d, t_sp *sp)
{
	int	i;

	i = 64;
	//if (DEBUG && (d->no || d->so || d->we || d->ea))
		// write(1, "questo non e' sbagliato", 25);
	sp->sn = mlx_xpm_file_to_image(d->mlx, d->no, &i, &i);
	sp->sps = mlx_xpm_file_to_image(d->mlx, d->so, &i, &i);
	sp->sw = mlx_xpm_file_to_image(d->mlx, d->we, &i, &i);
	sp->se = mlx_xpm_file_to_image(d->mlx, d->ea, &i, &i);
	if (!sp->sn || !sp->sps || !sp->sw || !sp->se)
	{
		free(d->no);
		free(d->so);
		free(d->we);
		free(d->ea);
		d->no = NULL;
		d->so = NULL;
		d->we = NULL;
		d->ea = NULL;
		return (-99999);
	}
	return (1);
}

static int	get_color(char **mtx)
{
	int	rgb[3];

	rgb[0] = ft_atoi(mtx[0]);
	rgb[1] = ft_atoi(mtx[1]);
	rgb[2] = ft_atoi(mtx[2]);
	return (rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

int	set_colors(t_textures *txt, t_details *dets)
{
	int	i;

	if (dets->mf && dets->mc)
	{
		i = 0;
		while (dets->mf[i])
		{
			if (ft_atoi(dets->mf[i]) > 255 || ft_atoi(dets->mf[i]) < 0)
				return (0);
			txt->f = get_color(dets->mf);
			i++;
		}
		i = 0;
		while (dets->mc[i])
		{
			if (ft_atoi(dets->mc[i]) > 255 || ft_atoi(dets->mc[i]) < 0)
				return (0);
			txt->c = get_color(dets->mc);
			i++;
		}
	}
	return (1);
}

int	check_map_h_w(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
			j++;
		if (j > map->w_map)
		{
			map->w_map = j;
			if (i != 0 && i != map->map_lines)
			{
				if (check_mid_full_walls(map, i))
					return (1);
			}
		}
		i++;
	}
	map->h_map = i;
	return (0);
}