/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:30:15 by negambar          #+#    #+#             */
/*   Updated: 2024/12/02 11:49:02 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_attrs(t_details *dets, t_sprites *sp)
{
	int	i;

	i = 0;
	sp->x = 64;
	sp->y = 64;
	sp->spriteN = NULL;
	sp->spriteS = NULL;
	sp->spriteW = NULL;
	sp->spriteE = NULL;
	dets->no = NULL;
	dets->so = NULL;
	dets->we = NULL;
	dets->ea = NULL;
}

static int set_attrs(char **mtx, t_details *dets, int trimmed)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i <= trimmed)
	{
		if (mtx[i][j] == 'N' && mtx[i][j + 1] == 'O')
			dets->no = ft_strdup(&mtx[i][3]);
		if (mtx[i][j] == 'S' && mtx[i][j + 1] == 'O')
			dets->so = ft_strdup(&mtx[i][3]);
		if (mtx[i][j] == 'W' && mtx[i][j + 1] == 'E')
			dets->we = ft_strdup(&mtx[i][3]);
		if (mtx[i][j] == 'E' && mtx[i][j + 1] == 'A')
			dets->ea = ft_strdup(&mtx[i][3]);
		if (mtx[i][j] == 'F')
			dets->mf = ft_split(&mtx[i][2], ',');
		if (mtx[i][j] == 'C')
			dets->mc = ft_split(&mtx[i][2], ',');
		i++;
	}
	if (!dets->no || !dets->so || !dets->we || !dets->ea || !dets->mf || !dets->mc)
		return (0);
	return (1);
}

static int	check_txtrs_utils(char **mtx, int i)
{
	int x;

	x = 0;
	if (ft_strncmp(mtx[i], "C", 1) == 0)
		x++;
	if (ft_strncmp(mtx[i], "F", 1) == 0)
		x++;
	return (x);
}

int	check_txtrs(char **mtx, int trimmed, int i)
{
	int	j;
	int	x;

	j = i;
	x = 0;
	while (i <= trimmed)
	{
		if (ft_strncmp(mtx[i], "NO", 2) == 0)
			x++;
		else if (ft_strncmp(mtx[i], "SO", 2) == 0)
			x++;
		else if (ft_strncmp(mtx[i], "WE", 2) == 0)
			x++;
		else if (ft_strncmp(mtx[i], "EA", 2) == 0)
			x++;
		x += check_txtrs_utils(mtx, i);
		i++;
	}
	if (x == 6)
		return (1);
	else
		printf("ERROR\n");
	return (0);
}

int check_extras(char **mtx, t_details *dets, t_sprites *sp, int trimmed)
{
	int	i;

	i = 0;
	while (mtx[i][0] == ' ' || mtx[i][0] == '\t' || mtx[i][0] == '\n' || mtx[i][0] == '\0')
		i++;
	if (!check_txtrs(mtx, trimmed, i))
		return (-9999);
	if (!set_attrs(mtx, dets, trimmed))
		return (-9999);
	if (!check_wall_available(dets, sp))
		return (-9999);
	return (1);
}