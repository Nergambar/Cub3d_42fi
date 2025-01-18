/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_check.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:30:15 by negambar          #+#    #+#             */
/*   Updated: 2025/01/10 13:47:47 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_attrs(t_game *game)
{
	int	i;

	i = 0;
	game->t.x = 64;
	game->t.y = 64;
	game->t.sn = NULL;
	game->t.sps = NULL;
	game->t.sw = NULL;
	game->t.se = NULL;
	game->dets.no = NULL;
	game->dets.so = NULL;
	game->dets.we = NULL;
	game->dets.ea = NULL;
}

static int	set_attrs(char **mtx, t_details *dets, int trimmed)
{
	int	i;
	int	j;

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
	if (!dets->no || !dets->so || !dets->we \
	|| !dets->ea || !dets->mf || !dets->mc)
		return (0);
	return (1);
}

static int assign(char **mtx, char *s, t_details *dets)
{
	int j;

	j = 0;
	while (mtx[j])
	{
		if (ft_strncmp(mtx[j], s, 2))
		{
			if (ft_strcmp(s, "NO"))
				dets->no = mtx[j];
			if (ft_strcmp(s, "SO"))
				dets->so = mtx[j];
			if (ft_strcmp(s, "EA"))
				dets->ea = mtx[j];
			if (ft_strcmp(s, "WE"))
				dets->we = mtx[j];
		}	
		j++;
	}
	if (!dets->no && !dets->so && !dets->ea && !dets->we)
		return (0);
	return (1);
}

int	check_txtrs(char **mtx, int trimmed, int i, t_details *dets)
{
	int	j;
	int	x;

	j = i;
	x = 0;
	while (i <= trimmed)
	{
		if (ft_strncmp(mtx[i], "NO", 2) == 0)
		{
			if(assign(mtx, "NO", dets))
				x++;
		}
		else if (ft_strncmp(mtx[i], "SO", 2) == 0)
		{
			if(assign(mtx, "SO", dets))
				x++;
		}
		else if (ft_strncmp(mtx[i], "WE", 2) == 0)
		{
			if(assign(mtx, "WE", dets))
				x++;
		}
		else if (ft_strncmp(mtx[i], "EA", 2) == 0)
		{
			if(assign(mtx, "EA", dets))
				x++;
		}
		i++;
	}
	if (x == 4)
		return (1);
	else
		printf("ERROR\n");
	return (0);
}

int	check_extras(char **mtx, t_game *game, int trimmed)
{
	int	i;

	i = 0;
	// (void)sp;
	while (mtx[i][0] == ' ' || mtx[i][0] == '\t' \
	|| mtx[i][0] == '\n' || mtx[i][0] == '\0')
		i++;
	if (!check_txtrs(mtx, trimmed, i, &game->dets))
		return (-9999);
	if (!set_attrs(mtx, &game->dets, trimmed))
		return (-9999);
	if (!check_wall_available(&game->dets, &(game->t)))
		return (-9999);
	return (1);
}
