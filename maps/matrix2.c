/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:33 by negambar          #+#    #+#             */
/*   Updated: 2025/01/10 13:52:57 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	freemtx(char **mtx)
{
	int	i;

	i = 0;
	if (mtx)
	{
		while (mtx[i])
		{
			free(mtx[i]);
			i++;
		}
		free(mtx);
	}
}

char	**map_mtx(char **mtx, char *av, t_game *game)
{
	char	**copy;
	int		i;
	int		j;

	copy = (char **)ft_calloc(((get_height(av) - mtx_trim(mtx)) + 1), \
	sizeof(char *));
	if (!copy)
		return (NULL);
	i = mtx_trim(mtx) + 1;
	while (!empy_line(mtx[i]))
		i++;
	j = 0;
	while (mtx[i])
	{
		copy[j] = ft_strdup(mtx[i]);
		if (!copy[j])
			return (freemtx(copy), NULL);
		i++;
		j++;
	}
	copy[j] = NULL;
	freemtx(mtx);
	game->map = copy;
	return (copy);
}

void	printfchecks(t_details dets, t_textures txt)
{
	printf("NO:%s\n", dets.no);
	printf("SO:%s\n", dets.so);
	printf("WE:%s\n", dets.we);
	printf("EA:%s\n", dets.ea);
	if (txt.c && txt.f)
	{
		printf("F:%d\n", txt.f);
		printf("C:%d\n", txt.c);
	}
}

char	**initial_checks(char **av, t_game *game)
{
	char	**mtx;
	int		t;
	int		fd;

	mtx = NULL;
	fd = open(av[1], O_RDONLY);
	mtx = mtxdup(av, fd);
	if (!mtx)
		return (printf("ERROR\ncheck again"), NULL);
	t = mtx_trim(mtx);
	if (!check_extras(mtx, game, t))
		return (NULL);
	close(fd);
	return (mtx);
}
