/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:53:12 by negambar          #+#    #+#             */
/*   Updated: 2024/11/28 11:59:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**mtx_init(char **av, int fd)
{
	char **copy;
	int i;
	int height;
	int width;
	char *line;

	height = get_height(av[1]);
	width = get_max_width(av[1]);
	if(!height || !width)
		return (NULL);
	copy = (char **)ft_calloc((height + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while ((line = get_the_line(fd)) != NULL)
	{
		copy[i] = ft_strdup(line);
		i++;
		free(line);
	}
	free(line);
	return (copy);
}

char	*get_the_line(int fd)
{
	char *str;
	char *tmp;
	size_t len;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	str = ft_strtrim(tmp, "\n");
	free(tmp);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	str[len] = '\0';
	return (str);
}

char **mtxdup(char **av, int fd)
{
	char **copy;

	if (!ft_strrchr2(av[1], ".cub"))
		return (NULL);
	copy = mtx_init(av, fd);
	if (!copy)
		return (NULL);
	return (copy);
}

int main(int ac, char **av)
{
	char **mtx;
	int fd;
	int trimmed;
	int i;
	t_details dets;
	t_textures txt;

	init_attrs(&dets);
	if (ac == 1)
		return (0);
	fd = open("test.cub", O_RDONLY);
	if (fd < 0)
		return(printf("ERROR\n"), 1);
	mtx = mtxdup(av, fd);
	if (!mtx)
		return(printf("ERROR\n"), 1);
	trimmed = mtx_trim(mtx);
	if (!check_extras(mtx, &dets, trimmed, 0))
	{
		printf("ERROR\n");
		return (1);
	}
	mtx = map_mtx(mtx, av[1]);
	i = -1;
	while (mtx[++i])
		printf	("%s\n", mtx[i]);
	if (!set_colors(&txt, &dets))
	{
		printf("ERROR\n");
		return (1);
	}
/* 				todo			 */
	printf("NO:%s\n", dets.no);
	printf("SO:%s\n", dets.so);
	printf("WE:%s\n", dets.we);
	printf("EA:%s\n", dets.ea);
	printf("C:%d\n", txt.c);
	printf("F:%d\n", txt.f);
/* 				todo			 */
	close(fd);
	freeatts(&dets);
	freemtx(mtx);
}
