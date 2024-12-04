/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_wallcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 11:31:47 by negambar          #+#    #+#             */
/*   Updated: 2024/12/02 12:17:51 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_wall_available(t_details *details, t_sprites *sprites)
{
	sprites->spriteN = mlx_xpm_file_to_image(details->mlx, details->no, &sprites->x, &sprites->y);
	sprites->spriteS = mlx_xpm_file_to_image(details->mlx, details->so, &sprites->x, &sprites->y);
	sprites->spriteW = mlx_xpm_file_to_image(details->mlx, details->we, &sprites->x, &sprites->y);
	sprites->spriteE = mlx_xpm_file_to_image(details->mlx, details->ea, &sprites->x, &sprites->y);
	if (!sprites->spriteN || !sprites->spriteS || !sprites->spriteW || !sprites->spriteE)
	{
		free(details->no);
		free(details->so);
		free(details->we);
		free(details->ea);
		details->no = NULL;
		details->so = NULL;
		details->we = NULL;
		details->ea = NULL;
		return (-99999);
	}
	return (1);
}
