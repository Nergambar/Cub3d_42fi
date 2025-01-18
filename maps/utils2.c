/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 12:38:25 by negambar          #+#    #+#             */
/*   Updated: 2024/12/20 19:06:09 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**utils(char **av)
{
	char **mtx;
	char **dup = NULL;
	int	t;
	int i;

	t = 0;
	i = 0;
	int	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (NULL);
	mtx = mtxdup(av, fd);
	close(fd);
	if (!mtx)
		return (NULL);
	t = mtx_trim(mtx);
	while (mtx[t] && (mtx[t][0] == '\0' || mtx[t][0] == '\n'))
	{
		t++;
	}
	dup = (char **)ft_calloc((t + 1), sizeof(char *));
	if (!dup)
	{
		freemtx(mtx);
		return (NULL);
	}
	i = t;
	while (mtx[i])
	{
		dup[i - t] = ft_strdup(mtx[i]);
		// printf("dup[i]:%s\n", dup[i - t]);
		if (!dup[i - t])
		{
			while (t <= i)
				free(dup[t - t]);
			free(dup);
			freemtx(mtx);
			return (NULL);
		}
		i++;
	}
	dup[i - t] = NULL;
	freemtx(mtx);
	return (dup);
}