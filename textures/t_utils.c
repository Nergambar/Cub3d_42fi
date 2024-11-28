/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:46:02 by negambar          #+#    #+#             */
/*   Updated: 2024/11/28 11:58:49 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	freeatts(t_details *dets)
{
	if (dets)
	{
		if (dets->no)
			free(dets->no);
		if (dets->so)
			free(dets->so);
		if (dets->we)
			free(dets->we);
		if (dets->ea)
			free(dets->ea);
		if (dets->mf)
			freemtx(dets->mf);
		if (dets->mc)
			freemtx(dets->mc);
	}
}

int	set_colors(t_textures *txt, t_details *dets)
{
	int i;
	if (dets->mf && dets->mc)
	{
		i = 0;
		while (dets->mf[i])
		{
			if (ft_atoi(dets->mf[i]) > 255 || ft_atoi(dets->mf[i]) < 0)
				return (0);
			txt->f = ft_atoi(dets->mf[i]);
			i++;
		}
		i = 0;
		while (dets->mc[i])
		{
			if (ft_atoi(dets->mc[i]) > 255 || ft_atoi(dets->mc[i]) < 0)
				return (0);
			txt->c = ft_atoi(dets->mc[i]);
			i++;
		}
	}
	return (1);
}