/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 11:40:33 by negambar          #+#    #+#             */
/*   Updated: 2024/12/04 11:21:09 by negambar         ###   ########.fr       */
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

char	**map_mtx(char **mtx, char *av)
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
	return (copy);
}
